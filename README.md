# mars-rover
Ce projet est une collaboration entre le Robotix (ESIX - Caen) et le MBOT (ENSISA - Mulhouse). Le but est de créer une architecture basée sur ROS et Arduino pour piloter un rover inspiré de ceux de la NASA. A terme, le rover devra reconnaitre son environnement et s'y déplacer de manière complètement autonome.

## Installation d'Ubuntu 24.04
**IMPORTANT** : différents PC amènent différents problèmes ! Parmis les différentes EMMERDES rencontrées, on peut lister (non exaustif):

- Désactivation de BitLocker : certains Windows viennent encryptés par défaut, on les reconnait au cadenas sur le disque C: dans l'explorateur de fichier. MARCHE À SUIVRE :
	 - Cliquez sur Système et sécurité, puis sur Chiffrement de lecteur BitLocker.
	- Recherchez le lecteur concerné (souvent le lecteur C:).
	- Cliquez sur Désactiver BitLocker.
	- Confirmez votre choix. Le déchiffrement se lance en arrière-plan.
- Désactivation du Secure Boot : si on souhaite conserver une installation Windows à coté d'Ubuntu, il est nécessaire de désactiver le Secure Boot. MARCHE à SUIVRE :
	- Accéder au BIOS et trouver l'option Secure Boot. Elle se trouve soit dans Sécurité, soit dans Boot, soit dans General/Information/Main/etc...
	- La désactiver !
	- Si l'option est grisée : dans Sécurité, créer le mot de passe administrateur (une seule lettre) et retourner désactiver l'option.
- Désactivation d'Intel Rapid Storage Technology : Intel a une technologie d'accélération du stockage (peu visible psk Windows est un énorme tas :-) ) qui n'est pas compatible avec Linux. ATTENTION : il y a possibilité de bloquer complètement Windows en désactivant cette option! La solution appliquée a été la nucléarisation du système. Il est possible de conserver Windows comme précédemment, mais non testé donc.
	- Si on veut désactiver Intel RST: certains BIOS (Acer...) peuvent cacher l'option. Le raccourci pour l'afficher est **`Ctrl+S`**.

Suivre ce tutoriel pour installer Ubuntu: https://www.youtube.com/watch?v=FKHX_xXyZhU
Utiliser l'ISO Desktop: https://releases.ubuntu.com/noble/

## Installation de ROS
Source : https://docs.ros.org/en/jazzy/Installation/Ubuntu-Install-Debs.html

On vérifie que l'option LANG contient bien UTF-8 pour éviter les soucis. Une autre valeur ne pose normalement pas de problème.
```
locale
```
Si la valeur ne contient pas UTF-8:
```
sudo apt update && sudo apt install locales
sudo locale-gen fr_FR fr_FR.UTF-8
sudo update-locale LC_ALL=fr_FR.UTF-8 LANG=fr_FR.UTF-8
export LANG=fr_FR.UTF-8
```
On peut ensuite installer ROS, on ajoute les sources nécessaires et le repo de ROS.
```
sudo apt install software-properties-common
sudo add-apt-repository universe
sudo apt update && sudo apt install curl -y
export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F'"' '{print $4}')
curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo ${UBUNTU_CODENAME:-${VERSION_CODENAME}})_all.deb"
sudo dpkg -i /tmp/ros2-apt-source.deb
```
