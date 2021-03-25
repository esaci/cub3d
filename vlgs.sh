make
CUB=cub3D;MAP=map.cub;valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrind_log ./cub3D map.cub --save;grep -A1 valgrind valgrind_log|grep cub3D
