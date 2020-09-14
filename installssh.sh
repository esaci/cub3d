ssh-keygen -t rsa -b 4096 -C "esaci@student.42.fr"
eval "$(ssh-agent -s)"
ssh-add -K ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub
