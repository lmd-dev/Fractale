Paramètres en ligne de commande :
 -x [double] 		X du centre de la zone à observer
 -y [double] 		Y du centre de la zone à observer
 -w [double] 		Largeur de la zone à observer

 -ow [int] 		Largeur des images à produire
 -oh [int]		Hauteur des images à produire

 -t [string]		Type de fractale à générer (julia / mandelbrot)
 -itmax [int]		Nombre d'itérations maximum

 -f [string]		Nom de base (sans extension) du fichier de sortie des images
 -frames [int]		Nombre d'images à produire
 -zoomstep [double]	Coefficient de zoom à appliquer entre deux images
 -itmaxstep [double]	Coefficient multiplicateur sur itmax entre deux images

 -threads [int]		Nombre de threads à utiliser

Mandelbrot area :
	-t mandelbrot
	-x -0.65
	-y 0
	-w 4
	-itmax 500

Julia area :
	-t julia
	-x 0
	-y 0
	-w 4
	-itmax 500