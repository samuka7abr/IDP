read -p "Quantas questoes? " q
mkdir -p prova
cd prova

template='#include <bits/stdc++.h>
using namespace std;
#define otim ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 1e9;
const ll INF_LL = 1e18; 

int main(){
    otim;
    
    return 0;
}'

for ((i=1; i<=q; i++)); do
  qn=$(printf "%02d" "$i")
  letra=$(printf "\\$(printf '%03o' $((64 + i)))") 
  mkdir -p "$qn/args"
  echo "$template" > "$qn/${letra}.cpp"
  touch "$qn/args/input"
  touch "$qn/args/expected"
done

echo "Base da prova criada em: $(pwd)"
