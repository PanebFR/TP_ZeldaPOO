TP_ZeldaPOO
===========

Rendu concernant IHM en C++ avec QTCreator

Liste des dossiers et fichier :
Racine:
	Affichage normal
	Images
	Release
	Sources
	README
	

Compilation et lancement :
	-Générez un nouveau projet sur QTCreator de type Application, sous type Qt Widgets Application. Nommez-le et placez-le comme vous voulez.
Compiez ensuite dans ce dossier tout le contenu du dossier sources main et le ui seront écrasés. 
Clic droit dans QTCreator sur le projet, puis Add existing files, Ctrl+A et ajoutez-les tous.
Ctrl+B pour build le projet.
Dans le nouveau dossier créé après votre build (à priori build-VotreNom-Desktop-Debug ou build-VotreNom-Desktop-Release selon le mode d'assemblement de Qt), placez le
dossier image. Des messages d'erreurs s'afficheront si les ressources ne sont pas trouvées (uniquement si le programme est lancé en mode console).
Ctrl+R pour lancer l'application. Le jeu considère comme de la triche de charger directement les niveaux 2 et 3. Pour gagner il faut commencer du un (récompense à
améliorer encore).
Les escaliers ne s'activent que si les rubis sont tous ramassés.

29.10.2014 :
Mis en ligne version Martin T. Ajout des flèches + mise à jour paramétre cap initial de notre héros.
28.10.2014 :
Mis en ligne version Martin T. avec gestion des attaques par leur direction (opposées + biais)
27.10.2014 :
Mis en ligne version Martin T.
Coeur bonus dispo lvl 2 et 3 (respectivement 1 et 2). La vie passe à 4 + fullregen.

En cours : 
	-ajout attaque unidirectionnelle (reste à travailler le semi directionnel)
	-ajout des potions sur les SwordMoblins
	-<mise en place de la continuité du coeur Bonus ?>
	-<ajout d'une attaque spéciale ?>


