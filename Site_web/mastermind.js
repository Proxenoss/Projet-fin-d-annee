const colors = ["red", "blue", "green", "yellow", "purple", "orange"];
let secretCode = [];
let guess = [];

function openPopup() {
  document.getElementById("popup").style.display = "block";
  resetGame();
}

function closePopup() {
  document.getElementById("popup").style.display = "none";
}

function resetGame() {
  guess = [];
  secretCode = Array.from({ length: 4 }, () => colors[Math.floor(Math.random() * colors.length)]);
  document.getElementById("feedback").innerText = "";
  document.getElementById("current-guess").innerText = "";
  renderColorButtons();
}

function renderColorButtons() {
  const container = document.getElementById("color-picker");
  container.innerHTML = "";
  colors.forEach(color => {
    const btn = document.createElement("button");
    btn.className = "color-btn";
    btn.style.backgroundColor = color;
    btn.onclick = () => addColor(color);
    container.appendChild(btn);
  });
}

function addColor(color) {
  if (guess.length >= 4) return;
  guess.push(color);
  document.getElementById("current-guess").innerText = "Choix en cours : " + guess.join(", ");
}

function submitGuess() {
  if (guess.length !== 4) {
    alert("Choisissez exactement 4 couleurs.");
    return;
  }

  let bienPlace = 0;
  let malPlace = 0;
  const codeCopy = [...secretCode];
  const guessCopy = [...guess];

  // Vérifie les couleurs bien placées
  for (let i = 0; i < 4; i++) {
    if (guess[i] === secretCode[i]) {
      bienPlace++;
      codeCopy[i] = null;
      guessCopy[i] = null;
    }
  }

  // Vérifie les couleurs mal placées
  for (let i = 0; i < 4; i++) {
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

  if (bienPlace === 4) {
    feedback.innerText += "🎉 Bravo, tu as trouvé le code !\n";
    setTimeout(() => {
    window.location.href = "07.html";
  }, 2000);
  }

  guess = [];
  document.getElementById("current-guess").innerText = "";
}
