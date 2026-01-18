# 🚖 Crazy Taxi Micro:bit

> Une adaptation innovante du jeu d'arcade classique **Crazy Taxi** pour le micro-contrôleur BBC Micro:bit. Esquivez les obstacles, survivez le plus longtemps possible et battez votre record sur une matrice LED 5x5 !

![Crazy Taxi Gameplay](assets/Crazy_Taxi-Logo.png)

---

## 🎮 À propos

**Crazy Taxi Micro:bit** est un jeu de conduite développé entièrement en C++ pour le BBC Micro:bit. Le joueur contrôle un taxi qui doit éviter les obstacles sur une route à trois voies. La difficulté augmente progressivement avec l'accélération du jeu, offrant un gameplay addictif et challengeant.

### 🎯 Objectifs du projet

- Créer une expérience de jeu fluide et addictive sur un écran LED 5x5
- Exploiter au maximum les capacités limitées du Micro:bit
- Développer un code modulaire, optimisé et bien documenté
- Offrir un gameplay dynamique avec génération procédurale d'obstacles

### ⚡ Contraintes techniques relevées

- **Affichage limité** : Matrice LED 5x5 pixels
- **Contrôles** : Deux boutons uniquement (A et B)

---

## ✨ Fonctionnalités

✅ **Déplacement fluide** du taxi sur 3 voies  
✅ **Génération aléatoire** d'obstacles pour une rejouabilité infinie  
✅ **Détection de collision** précise et instantanée  
✅ **Accélération progressive** pour une difficulté croissante  
✅ **Affichage du score** : le temps de survie  
✅ **Délimitation visuelle** de la route avec lignes de sécurité  
✅ **Compatible** avec Micro:bit V1 et V2  
✅ **Aucun bug** détecté lors des tests exhaustifs  

---

## 🛠️ Matériel requis

- **BBC Micro:bit** (V1 ou V2)
- **Câble USB** pour la programmation
- **Batterie** (optionnelle, pour jouer en mode portable)

---

## 📥 Installation

### Méthode 1 : Compilation avec Arduino IDE

#### 1.1 Télécharger Arduino IDE

Téléchargez et installez la dernière version de l'environnement de développement Arduino depuis le [site officiel](https://www.arduino.cc/en/software).

#### 1.2 Ajouter le gestionnaire nRF5

1. Dans Arduino IDE, allez dans **Fichier → Préférences**
2. Ajoutez cette URL dans **"Gestionnaire de cartes supplémentaires"** :
   ```
   https://sandeepmistry.github.io/arduino-nRF5/package_nRF5_boards_index.json
   ```
3. Cliquez sur **OK**

#### 1.3 Installer les cartes Nordic

1. Allez dans **Outils → Type de carte → Gestionnaire de cartes**
2. Recherchez **"nRF5"**
3. Installez **"Nordic Semiconductor nRF5 Boards"** par Sandeep Mistry

#### 1.4 Sélectionner la carte

1. Ouvrez le fichier `CrazyTaxi_MicroBit.ino` dans Arduino IDE
2. Allez dans **Outils → Type de carte → Nordic Semiconductor nRF5 Boards**
3. Sélectionnez **BBC micro:bit** (V1) ou **BBC micro:bit V2** selon votre modèle

#### 1.5 Choisir le port

1. Connectez votre **micro:bit** via USB
2. Allez dans **Outils → Port**
3. Sélectionnez le port correspondant :
   - **COM** suivi d'un numéro sur Windows (ex: COM3)
   - **/dev/tty** sur macOS/Linux (ex: /dev/ttyACM0)

#### 1.6 Compiler et téléverser

1. Cliquez sur le bouton **Téléverser** (→) pour compiler et envoyer le programme
2. Le premier téléversement peut prendre quelques minutes
3. Une fois terminé, le jeu se lance automatiquement sur votre micro:bit ! 🎮

---

## 🎮 Comment jouer

### Commandes

- **Bouton A** : Déplacer le taxi vers la **gauche**
- **Bouton B** : Déplacer le taxi vers la **droite**

### Règles du jeu

1. Votre taxi avance automatiquement
2. Esquivez les obstacles qui descendent vers vous
3. Restez sur la route délimitée par les lignes de sécurité
4. Le jeu accélère progressivement pour augmenter la difficulté
5. La partie se termine si vous touchez un obstacle
6. Votre score final correspond au temps de survie

### 🏆 Conseils

- Anticipez les mouvements : les obstacles descendent de plus en plus vite
- Restez au centre quand possible pour avoir plus d'options d'esquive
- Ne paniquez pas : des mouvements calmes et précis sont la clé !

---

## 🏗️ Architecture technique

### Structure du projet

```
CrazyTaxi_Micro-Bit/
│
├── README.md                  # Documentation du projet
│
├── assets/                    # Ressources graphiques
│   └── CrazyTaxi_MicroBit.ino    # Code source principal
|   └── Crazy_Taxi-Logo.png
│
├── docs/                      # Documentation technique
│   └── tests_effectués.pdf     # Rapport de tests détaillé
│
└── releases/                  # Fichiers compilés
    └── CrazyTaxi_MicroBit.ino
```

### Technologies utilisées

- **Langage** : C++
- **Plateforme** : BBC Micro:bit (ARM Cortex-M0/M4)
- **Microcontrôleur** : Nordic nRF51822 (V1) / nRF52833 (V2)
- **Outils** : Arduino IDE avec support nRF5
- **Affichage** : Matrice LED 5×5 pixels
- **Mémoire** : 16KB RAM (V1) / 128KB RAM (V2)

---

## ✅ Tests et validation

Le projet a été rigoureusement testé selon un protocole complet :

### Tests de gameplay (10/10 validés)

- ✅ Avancement automatique du taxi
- ✅ Déplacement gauche/droite fonctionnel
- ✅ Détection de collision précise
- ✅ Taxi ne sort pas de la route
- ✅ Affichage correct des résultats
- ✅ Accélération progressive
- ✅ Lignes de sécurité visibles
- ✅ Pas de bug lors de doubles appuis
- ✅ Génération aléatoire fonctionnelle
- ✅ Lancement du programme sans erreur

### Tests de qualité du code (100% validés)

- ✅ Nommage des variables et constantes conforme
- ✅ Fonctions modulaires et bien nommées
- ✅ Indentation et présentation correctes
- ✅ Séparateurs et organisation du code
- ✅ Documentation complète (en-têtes, commentaires)

**Résultat** : **0 bug détecté** lors des tests finaux ! 🎉

Pour plus de détails, consultez le [rapport de test complet](docs/rapport-de-test.pdf).

---

## 👥 L'équipe

Ce projet a été développé par une équipe de 4 développeurs passionnés :

| Membre | Rôle | Responsabilités |
|--------|------|-----------------|
| **Tomás DE ALMEIDA** | RD - Chef de projet Développement | Direction du projet, coordination de l'équipe, développement principal |
| **Furkan AKTAS** | RW - Responsable Communication WEB | Développement du site web, communication du projet, documentation en ligne |
| **Hakan OZATA** | RC - Responsable Conception/Documentation | Architecture du jeu, conception technique, rédaction de la documentation |
| **Emirhan KARAHAN** | RQ - Responsable Qualité | Tests fonctionnels, validation du code, contrôle qualité, rapport de test |

---

## 🤝 Contributions

Les contributions sont les bienvenues ! Si vous souhaitez améliorer le jeu :

1. Forkez le projet
2. Créez une branche pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`)
3. Committez vos changements (`git commit -m 'Add some AmazingFeature'`)
4. Poussez vers la branche (`git push origin feature/AmazingFeature`)
5. Ouvrez une Pull Request

---

## 📞 Contact

Pour toute question ou suggestion :

- 🐛 Ouvrez une [issue](https://github.com/Furkan-dev768/CrazyTaxi_Micro-Bit/issues)
- ⭐ N'oubliez pas de mettre une étoile si vous aimez le projet !

---

**Fait avec ❤️ par l'équipe Crazy Taxi Micro:Bit - Tomás - Furkan - Hakan - Emirhan**
