# Organisation du projet F1 Games telemetry

## Réception des paquets
Il s'agit de la fonctionnalité principale de l'application : recevoir les paquets UDP du jeu afin de les traiter d'une certaine manière.

Voici le parcours d'un paquet : data-listener > packet-manager > global-packet > packet-manager > queues (copie)

### data listener
Cet objet permet de configurer l'écoute des paquets. Voici ses méthodes :
- Constructeur ==> permet de configurer les infos de bases (n° de port, protocol, etc.)
- initSocket ==> création de la socket et activation du mode écoute
- listen ==> une boucle pour recevoir les paquets puis les envoyer vers le packet manager (s'arrête si l'attribut stop est à true)

### packet manager
Il s'agit du manager de paquet. Après avoir reçu un paquet brut, il saura quoi en faire selon le jeu, et vers quelle(s) queue(s) renvoyer ce paquet. Voici ses méthodes :
- Constructeur ==> selon le jeu, initialise un paquet global
- handlePacket ==> C'est via cette méthode que data listener envoi le paquet. Le manager fait transiter ce paquet vers le global packet pour l'enregistrer. Si ce paquet est conforme, il est envoyé vers les queues

### global packet
Il existe un paquet global par jeu F1. Il contient tous les différents paquets qui peuvent être reçu. Voici ses méthodes :
- update ==> permet de mettre à jour un des paquets si celui reçu est conforme. Il en retourne une copie


## Debug
