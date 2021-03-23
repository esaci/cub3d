sudo apt-get update
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
git clone https://github.com/42Paris/minilibx-linux.git
pwd > /home/user42/test
cd minilibx-linux
make
sudo apt install libxext-dev
sudo apt install libxrandr-dev
sudo apt install libx11-dev
sudo apt install libbsd-dev
sudo apt install libssl-dev
cd /usr/local/man/
sudo mkdir man1
cd /home/user42
cd "$(cat test)"
cd minilibx-linux
sudo cp man/man1/* /usr/local/man/man1/
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h  /usr/local/include/
