rm outputs.txt

echo "--------stack-------" >> outputs.txt
g++ stack_imp.cpp
./a.out >> outputs.txt


echo "--------queue-------" >> outputs.txt
g++ queue_imp.cpp
./a.out >> outputs.txt


echo "--------linklist-------" >> outputs.txt
g++ link_list.cpp
./a.out >> outputs.txt



echo "--------tree-------" >> outputs.txt
g++ tree_imp.cpp
./a.out >> outputs.txt



echo "--------bfs_dfs-------" >> outputs.txt
g++ bfs_dfs.cpp
./a.out >> outputs.txt
