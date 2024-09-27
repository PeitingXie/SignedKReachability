
DFS=1
query_time=2
construct_time=4
query_from_file=8
hop_changed=16
index_cost=32
scale=64
order_changed=128
graph_size=256

code=$((query_time | construct_time | query_from_file | hop_changed | index_cost | scale | order_changed | graph_size))

fileName="SignedKReachability"

# sed -i '1,4d' filename

mkdir data/higgs
cd  data
python3 gen.py



g++ -O3 SignedKReachability.cpp  -o SignedKReachability -std=c++17
./SignedKReachability data/higgs-social_network $code$
