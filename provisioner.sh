#!/bin/bash

# update ubuntu and install SO dependencies
curl -sL https://deb.nodesource.com/setup_4.x | sudo -E bash -
sudo apt-get update
sudo apt-get upgrade -y
sudo apt-get dist-upgrade -y

sudo apt-get install -y \
    build-essential \
    curl \
    g++ \
    git \
    golang \
    language-pack-en \
    libssl-dev \
    nodejs \
    python-pip

sudo apt-get autoremove -y
sudo apt-get autoclean -y

sudo locale-gen en


# download config files and set the machine up
wget -q https://raw.githubusercontent.com/deniscostadsc/dotfiles/master/.gitconfig
wget -q https://raw.githubusercontent.com/deniscostadsc/dotfiles/master/.vimrc
cp /vagrant/.marathon /home/vagrant/

echo '. /home/vagrant/.marathon' >> /home/vagrant/.bashrc
echo 'cd /vagrant' >> /home/vagrant/.bashrc


# install python dependencies
sudo -H pip install --upgrade pip
sudo -H pip install pep8 cpplint


# install nodejs and js dependencies
sudo npm install -g jshint jscs
