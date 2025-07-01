# flake8: noqa
import os
from urllib.parse import quote_plus
import pandas as pd 
import matplotlib.pyplot as plt 
from sqlalchemy import create_engine

password = quote_plus("1@Samuel1501")
host = "localhost"
port = "3306"
database = "atividade"
engine = create_engine(f"mysql+pymysql://root:{password}@{host}:{port}/{database}")

os.makedirs("plots", exist_ok=True)

df = pd.read_sql_query("SELECT * FROM mytable", engine)
df_sample = df.sample(n=len(df), random_state=42)

avg_price = df_sample.groupby("Brand")["Price"].mean().reset_index()
plt.figure()
plt.bar(avg_price["Brand"], avg_price["Price"])
plt.title("Preço Médio por Marca")
plt.xlabel("Marca")
plt.ylabel("Preço Médio")
plt.xticks(rotation=45, ha="right")
plt.tight_layout()
plt.savefig("plots/media_preco_marca.png")
plt.close()

plt.figure()
plt.hist(df_sample["Price"], bins=20)
plt.title("Distribuição de Preços")
plt.xlabel("Preço")
plt.ylabel("Frequência")
plt.tight_layout()
plt.savefig("plots/distribuicao_precos.png")
plt.close()

fuel_counts = df_sample["Fuel_Type"].value_counts()
plt.figure()
plt.pie(fuel_counts, labels=fuel_counts.index, autopct="%1.1f%%")
plt.title("Proporção por Tipo de Combustível")
plt.tight_layout()
plt.savefig("plots/prop_combustivel.png")
plt.close()

plt.figure()
plt.boxplot(df_sample["Price"], vert=False)
plt.title("Boxplot de Preços")
plt.xlabel("Preço")
plt.tight_layout()
plt.savefig("plots/boxplot_precos.png")
plt.close()
