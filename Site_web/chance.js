//La partie pour le stockage en ligne de la variable a été demandé à chat gpt
if (localStorage.getItem("chance") === null) {
  localStorage.setItem("chance", "50");
}

function getChance() {
  return parseInt(localStorage.getItem("chance")) || 0;
}

function setChance(value) {
  value = Math.max(0, Math.min(100, value)); 
  localStorage.setItem("chance", value.toString());
  mettreAJourChance();
}
//jusqu'ici en gros
function mettreAJourChance() {
  const barre = document.getElementById("chance-bar");
  const valeur = getChance();
  barre.style.width = valeur + "%";
  barre.textContent = "Bravoure : ";
}

function augmenterChance(x) {
  setChance(getChance() + x);
}

function diminuerChance(x) {
  setChance(getChance() - x);
}

function affichercrane(){
  const container = document.getElementById("cranedelalose");
  container.innerHTML = '<div class="crane">💀</div>';
  container.style.display = "block";
}
function afficherdrapeau(){
  const container = document.getElementById("youpi-container");
  container.innerHTML = '<div class="gagne">🏆</div>';
  container.style.display = "block";
}

function verifierPageEtDeclencherEffet() {
  const nomPage = window.location.pathname.split("/").pop();
  const resetPage = window.location.pathname.split("/").pop();
  const pagesBigUP = ["15.html","21.html"];
  const pagesmidUP = ["06.html","05.html"];
  const pageslowUP = ["03.html","14.html","16.html","20.html"];
  const pageDead =["99.html","90.html","91.html","92.html","93.html","94.html","95.html","96.html","97.html","98.html",]
  const pageWin =["27.html"]
  const pagesBigDOWN = ["04.html"];
  const pagesmidDOWN = ["12.html"];
  const pageslowDOWN = ["19.html"];
  const pageReset = ["01.html"];

  if (pageReset.includes(resetPage)) {
    setChance(50)
  }
  if (pagesBigUP.includes(nomPage)) {
    augmenterChance(15);
  }
    if (pagesmidUP.includes(nomPage)) {
    augmenterChance(10);
  }
    if (pageslowUP.includes(nomPage)) {
    augmenterChance(5);
  }
    if (pagesBigDOWN.includes(nomPage)) {
    diminuerChance(40);
  }
    if (pagesmidDOWN.includes(nomPage)) {
    diminuerChance(35);
  }
    if (pageslowDOWN.includes(nomPage)) {
    diminuerChance(30);
  }
    if (pageDead.includes(nomPage)) {
    affichercrane();
  }
    if (pageWin.includes(nomPage)) {
    afficherdrapeau();
  }
}

window.addEventListener("DOMContentLoaded", () => {
  mettreAJourChance();
  verifierPageEtDeclencherEffet();
});

function voilaTaChance() {
  return getChance();
}
