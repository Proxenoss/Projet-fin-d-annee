let difficulte = voilaTaChance();
const couleurs = ["red", "blue", "green", "yellow", "purple", "orange"];
let couleursutilisées;
let Code = [];
let guess = [];
let taille;

function openPopup() {
  document.getElementById("popup").style.display = "block";
  resetGame();
}

function resetGame() {
  guess = [];
  if (difficulte >= 65){
    couleursutilisées = couleurs.slice(0,5);
    taille = 3;
    Code = Array.from({ length:taille }, () => couleursutilisées[Math.floor(Math.random() * couleursutilisées.length)]);
  }
  else if (difficulte <= 30){
    couleursutilisées = couleurs;
    taille = 4;
    Code = Array.from({ length:taille }, () => couleursutilisées[Math.floor(Math.random() * couleursutilisées.length)]);
  }
  else{
    couleursutilisées = couleurs.slice(0,5);
    taille = 4;
    Code = Array.from({ length:taille }, () => couleursutilisées[Math.floor(Math.random() * couleursutilisées.length)]);
  }
  document.getElementById("feedback").innerText = "";
  document.getElementById("current-guess").innerText = "";
  renderColorButtons();
}

function renderColorButtons() {
  const container = document.getElementById("color-picker");
  container.innerHTML = "";
  couleursutilisées.forEach(color => {
    const btn = document.createElement("button");
    btn.className = "color-btn";
    btn.style.backgroundColor = color;
    btn.onclick = () => addColor(color);
    container.appendChild(btn);
  });
}

function addColor(color) {
  if (taille == 4){
    if (guess.length >= 4) return;
    guess.push(color);
    document.getElementById("current-guess").innerText = "Choix en cours : " + guess.join(", ");
  }
  else {
    if (guess.length >= 3) return;
    guess.push(color);
    document.getElementById("current-guess").innerText = "Choix en cours : " + guess.join(", ");
  }  
}

function submitGuess() {
  if (taille == 4){
    if (guess.length !== 4) {
      alert("Choisissez exactement 4 couleurs.");
      return;
    }
  }
  else if (taille == 3){
      if (guess.length !== 3) {
      alert("Choisissez exactement 3 couleurs.");
      return;
    }
  }

  let bienPlace = 0;
  let malPlace = 0;
  const codeCopy = [...Code];
  const guessCopy = [...guess];
//La partie vérification (jusqu'à "feedbak") a été fait par chat gpt
  for (let i = 0; i < taille; i++) {
    if (guess[i] === Code[i]) {
      bienPlace++;
      codeCopy[i] = null;
      guessCopy[i] = null;
    }
  }

  for (let i = 0; i < taille; i++) {
    if (guessCopy[i]) {
      const index = codeCopy.indexOf(guessCopy[i]);
      if (index !== -1) {
        malPlace++;
        codeCopy[index] = null;
      }
    }
  }

  const feedback = document.getElementById("feedback");
  feedback.innerText += `Essai : ${guess.join(", ")} ➜ ${bienPlace} bien placé(s), ${malPlace} mal placé(s)\n`;
// jusqu'ici
  if (bienPlace === taille) {
    feedback.innerText += "🎉 Bravo, tu as trouvé le code !\n";
    setTimeout(() => {
    window.location.href = "07.html";
  }, 2000);
  }

  guess = [];
  document.getElementById("current-guess").innerText = "";
}


