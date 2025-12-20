import pandas as pd
import numpy as np
import ipaddress
from sklearn.ensemble import IsolationForest
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
import matplotlib.pyplot as plt
import os

csv_path = "transactions.csv"
df = pd.read_csv(csv_path)

for c in df.columns:
    if df[c].dtype == object:
        df[c] = df[c].astype(str).str.strip().replace({"": np.nan})

df['Transaction_Date'] = pd.to_datetime(df['Transaction_Date'], errors='coerce')
df['Transaction_Time'] = pd.to_timedelta(df['Transaction_Time'], errors='coerce')
df['ts'] = pd.to_datetime(df['Transaction_Date'].astype(str) + " " + df['Transaction_Time'].astype(str), errors='coerce')
df['Customer_Age'] = pd.to_numeric(df['Customer_Age'], errors='coerce')
df['Purchase_Amount'] = pd.to_numeric(df['Purchase_Amount'], errors='coerce')
df['Fraud_Flag'] = pd.to_numeric(df['Fraud_Flag'], errors='coerce')
df['Footfall_Count'] = pd.to_numeric(df['Footfall_Count'], errors='coerce')

df['weekday'] = df['ts'].dt.weekday
df['hour'] = df['ts'].dt.hour

def ip_class(x):
    try:
        ip = ipaddress.ip_address(x)
    except:
        return 'invalid'
    if ip.is_private: return 'private'
    if ip.is_multicast: return 'multicast'
    if ip.is_reserved: return 'reserved'
    if ip.is_global: return 'global'
    return 'other'

df['IP_Class'] = df['IP_Address'].apply(ip_class)

def map_store_city(store_id):
    if pd.isna(store_id): return np.nan
    s = str(store_id).split('-')[-1].upper()
    m = {'LA':'Los Angeles','NYC':'New York','TOKYO':'Tokyo','SHANGHAI':'Shanghai'}
    return m.get(s, s.title())

df['Store_City'] = df['Store_ID'].apply(map_store_city)
df['Location_norm'] = df['Location'].astype(str).str.title()

def sku_expected_category(sku):
    if pd.isna(sku): return np.nan
    s = sku.upper()
    if 'SERUM' in s: return 'Serum'
    if 'MASC' in s: return 'Mascara'
    if 'BLUSH' in s: return 'Blush'
    if 'FOUND' in s: return 'Foundation'
    if 'LIP' in s: return 'Lipstick'
    return np.nan

df['Expected_Category'] = df['Product_SKU'].apply(sku_expected_category)

df['Product_Category'] = df['Product_Category'].fillna("Unknown")

kpi_by_loc = (
    df.groupby('Location_norm', dropna=False)
      .agg(revenue=('Purchase_Amount','sum'),
           transactions=('Transaction_ID','count'),
           aov=('Purchase_Amount','mean'))
      .reset_index()
      .sort_values('revenue', ascending=False)
)

kpi_by_store = (
    df.groupby('Store_ID', dropna=False)
      .agg(revenue=('Purchase_Amount','sum'),
           transactions=('Transaction_ID','count'),
           aov=('Purchase_Amount','mean'))
      .reset_index()
      .sort_values('revenue', ascending=False)
)

kpi_by_category = (
    df.groupby('Product_Category', dropna=False)
      .agg(revenue=('Purchase_Amount','sum'),
           transactions=('Transaction_ID','count'),
           aov=('Purchase_Amount','mean'))
      .reset_index()
      .sort_values('revenue', ascending=False)
)

kpi_by_tier = (
    df.groupby('Customer_Loyalty_Tier', dropna=False)
      .agg(revenue=('Purchase_Amount','sum'),
           transactions=('Transaction_ID','count'),
           aov=('Purchase_Amount','mean'))
      .reset_index()
      .sort_values('revenue', ascending=False)
)

hour_weekday_pivot = pd.pivot_table(
    df.dropna(subset=['weekday','hour']),
    index='weekday', columns='hour',
    values='Transaction_ID', aggfunc='count', fill_value=0
)

store_day = df.groupby(['Store_ID','Transaction_Date']).agg(
    transactions=('Transaction_ID','count'),
    footfall=('Footfall_Count','sum'),
    revenue=('Purchase_Amount','sum')
).reset_index()
store_day['conv_rate'] = np.where(store_day['footfall']>0, store_day['transactions']/store_day['footfall'], np.nan)

os.makedirs("output", exist_ok=True)

plt.figure()
kpi_by_loc.set_index('Location_norm')['revenue'].plot(kind='bar')
plt.title("Revenue by Location")
plt.ylabel("Revenue")
plt.tight_layout()
plt.savefig("output/revenue_by_location.png")
plt.close()

plt.figure()
kpi_by_store.set_index('Store_ID')['revenue'].plot(kind='bar')
plt.title("Revenue by Store")
plt.ylabel("Revenue")
plt.tight_layout()
plt.savefig("output/revenue_by_store.png")
plt.close()

plt.figure()
kpi_by_category.set_index('Product_Category')['revenue'].plot(kind='bar')
plt.title("Revenue by Category")
plt.ylabel("Revenue")
plt.tight_layout()
plt.savefig("output/revenue_by_category.png")
plt.close()

plt.figure()
kpi_by_tier.set_index('Customer_Loyalty_Tier')['revenue'].plot(kind='bar')
plt.title("Revenue by Loyalty Tier")
plt.ylabel("Revenue")
plt.tight_layout()
plt.savefig("output/revenue_by_tier.png")
plt.close()

plt.figure()
plt.imshow(hour_weekday_pivot, aspect='auto')
plt.title("Transactions Heatmap (Weekday vs Hour)")
plt.xlabel("Hour")
plt.ylabel("Weekday")
plt.colorbar(label="Transactions")
plt.tight_layout()
plt.savefig("output/transactions_heatmap.png")
plt.close()

plt.figure()
plt.scatter(store_day['footfall'], store_day['transactions'])
plt.xlabel("Footfall")
plt.ylabel("Transactions")
plt.title("Footfall vs Transactions by Store-Day")
plt.tight_layout()
plt.savefig("output/footfall_vs_transactions.png")
plt.close()

plt.figure()
df['Purchase_Amount'].plot(kind='hist', bins=20)
plt.title("Distribution of Purchase Amounts")
plt.xlabel("Amount")
plt.tight_layout()
plt.savefig("output/purchase_amount_distribution.png")
plt.close()
