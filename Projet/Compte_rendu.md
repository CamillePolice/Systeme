# Questions Projet

## Question 1
Le fichier se ralentit à la lecture quand on divise la fréquence par 2.
Au contraire quand on augmente, la lecture du fichier s'accélère.
On en conclut que le fait de modifier la fréquence modifie la vitesse de lecture.
Cela se produit car la lecture du fichier prend moins de temps étant donné que l'on augmente la fréquence de lecture des bytes.

## Question 2
La vitesse de lecture en sortie est 2x plus lente.
Cela s'explique par le fait que le stéréo possède un Sample Right et un Sample Left.
De ce fait, le mono doit attendre le changement de Sample pour continuer la lecture, ce qui explique sa vitesse de lecture plus lente

## Question 3
Le fichier est mal échantillonné, de ce fait, on ne lit pas le fichier dans sa totalité. On sera moins précis dans l'encodage des valeurs du ficher soit 256 valeurs au lieu de 4096 valeurs.
