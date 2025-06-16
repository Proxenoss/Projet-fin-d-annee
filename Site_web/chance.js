let chance = 50; // Valeur initiale entre 0 et 100

function mettreAJourChance() {
  const barre = document.getElementById("chance-bar");
  const valeur = Math.max(0, Math.min(100, chance)); // clamp entre 0 et 100
  barre.style.width = valeur + "%";
  barre.textContent = "Chance : " + valeur + "%";
}

// Exemples d’utilisation :
function augmenterChance(x) {
  chance += x;
  mettreAJourChance();
}

function diminuerChance(x) {
  chance -= x;
  mettreAJourChance();
}

// Initialisation
mettreAJourChance();
