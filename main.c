#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_SIZE 512

FILE* lecture_fichier_book () {
    FILE* book = fopen("../book2.txt", "r");
    if (!book) {
        fprintf(stderr, "Impossible d'ouvrir le fichier book.txt\n");
        exit(EXIT_FAILURE);
    };
    return book;
};
FILE* creation_page_web (char* nom) {
    FILE* page = fopen(nom, "w");
    if (!page) {
        fprintf(stderr,"Erreur dans la creation du fichier\n");
        exit(EXIT_FAILURE);
    }
    return page;
};
void creation_paragraphe (FILE* page, char* line) {
    char texte_principal[LINE_SIZE];
    sscanf(line, "<p>%[^<]</p>", texte_principal);
    fprintf(page,"<p>%s</p>\n",texte_principal);
};
void creation_choix (FILE* page, char* line) {
    char texte_principal[LINE_SIZE];
    int id = 0;
    sscanf(line, "<choice idref=\"%d\">%[^<]</choice>", &id, texte_principal);
    fprintf(page,"<a href=\"%02d.html\" class=\"box\">\n <p>%s<br><strong> Faire ce choix </strong></p>\n </a>\n",id, texte_principal);
};

int main() {
    char line[LINE_SIZE];
    FILE* book = lecture_fichier_book();
    FILE* page = NULL;

    while(fgets(line, sizeof(line), book)) {
        int id;
        char title[128];
        char nom[25];

        if (strstr(line, "<chapter")==line) {

            if (page != NULL) {
                fclose(page);
            }
            sscanf(line, "<chapter id=\"%d\">%[^<]</chapter>", &id, title);
            if (id == 100) {
                snprintf(nom, sizeof(nom), "../Site_web/%02d.html",id);
                page = creation_page_web(nom);
                fprintf(page,
                    "<!DOCTYPE html>\n"
                    "<html lang=\"fr\">\n"
                    "<head>\n"
                    "    <meta charset=\"UTF-8\">\n"
                    "    <title>%s</title>\n"
                    "    <link rel=\"stylesheet\" href=\"chance.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"style.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"mastermind.css\">\n"
                    "    <script src=\"chance.js\" defer> </script>"
                    "    <script src=\"mastermind.js\" defer> </script>"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "    <p>Vous devez réussir l'enigme et la créature vous donnera la pierre et la possibilité de continuer ta quête</p>"
                    "    <p>Règles du Mastermind : C'est un jeu de reflexion et de logique, lorsque vous lancerez le jeu cela va choisir entre 3 et 4 couleurs parmi les 5 ou 6 disponible (cela depend de votre bravoure). Il vous faudra faire des propositions pour deviner cette suite de couleurs, le jeu donnera des informations sur celles présentes et bien ou mal placées (les couleurs peuvent apparaitre plusieurs fois)</p>"
                    "    <button onclick=\"openPopup()\">Commencer l'égnime</button>"
                    "<div id=\"popup\" class=\"popup\">"
                    "   <div class=\"popup-content\">"
                    "       <h2>Mastermind</h2>"
                    "       <div id=\"color-picker\"></div>"
                    "       <div id=\"current-guess\"></div>"
                    "       <button onclick=\"submitGuess()\">Valider</button>"
                    "       <pre id=\"feedback\"></pre>"
                    "   </div>"
                    "</div>"
                    "    <div class=\"chance-container\">"
                    "       <div id=\"chance-bar\" class=\"chance-bar\">Bravoure chevaleresque</div>"
                    "    </div>"
                    "</body>\n",
                    title, title
                );
            }
            else if (id == 101) {
                snprintf(nom, sizeof(nom), "../Site_web/%02d.html",id);
                page = creation_page_web(nom);
                fprintf(page,
                    "<!DOCTYPE html>\n"
                    "<html lang=\"fr\">\n"
                    "<head>\n"
                    "    <meta charset=\"UTF-8\">\n"
                    "    <title>%s</title>\n"
                    "    <link rel=\"stylesheet\" href=\"chance.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"style.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"compteestbon.css\">\n"
                    "    <script src=\"chance.js\" defer> </script>"
                    "    <script src=\"compteestbon.js\" defer> </script>"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "<p>Pour récuperer cette seconde pierre il suffit de résoudre cette énigme</p>"
                    "<p>Les Règles du Compte est bon : Pour gagner il faut réussir à atteindre le chiffre en utlisant au maximum une fois les chiffres proposés et en utilisant l'addition, la soustraction, la multiplication et la division (+,-,*,/), attention à bien mettre les parenthèses</p>"
                    "<div id=\"jeu\">"
                    "   <div id=\"nombres\"></div>"
                    "       <p>Nombre à atteindre : <strong id=\"objectif\"></strong></p>"
                    "       <label for=\"solution\">Votre formule (ex: 100 + 75 - 50):</label>"
                    "       <input type=\"text\" id=\"solution\" placeholder=\"Entrez votre solution\">"
                    "       <br>"
                    "       <button onclick=\"verifierSolution()\">Soumettre</button>"
                    "       <div id=\"feedback\"></div>"
                    "   </div>"
                    "</div>"
                    "    <div class=\"chance-container\">"
                    "       <div id=\"chance-bar\" class=\"chance-bar\">Bravoure chevaleresque</div>"
                    "    </div>"
                    "</body>\n",
                    title, title
                );
            }
            else if (id == 102) {
                snprintf(nom, sizeof(nom), "../Site_web/%02d.html",id);
                page = creation_page_web(nom);
                fprintf(page,
                    "<!DOCTYPE html>\n"
                    "<html lang=\"fr\">\n"
                    "<head>\n"
                    "    <meta charset=\"UTF-8\">\n"
                    "    <title>%s</title>\n"
                    "    <link rel=\"stylesheet\" href=\"chance.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"style.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"combat.css\">\n"
                    "    <script src=\"chance.js\" defer> </script>"
                    "    <script src=\"combat.js\" defer> </script>"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "    <p>Pour récuperer cette dernière pierre vous devez réussir le combat</p>"
                    "    <p>Les règles du combat : Pour gagner vous devez cliquer au moment ou la barre rouge est dans l'encadré vert et réussir tous les niveaus (dont le nombre varie en fonction de la bravoure, attention ça accélère</p>"
                    "<div class=\"container\">"
                    "   <h2>Duel Niveau <span id=\"level\">1</span></h2>"
                    "   <div class=\"bar-container\">"
                    "       <div class=\"zone-verte\"></div>"
                    "       <div class=\"curseur\" id=\"curseur\"></div>"
                    "   </div>"
                    "   <br>"
                    "   <button id=\"attackBtn\">Attaquer</button>"
                    "   <p id=\"message\"></p>"
                    "</div>"
                    "    <div class=\"chance-container\">"
                    "       <div id=\"chance-bar\" class=\"chance-bar\">Bravoure chevaleresque</div>"
                    "    </div>"
                    "</body>\n",
                    title, title
                );
            }
            else {
                snprintf(nom, sizeof(nom), "../Site_web/%02d.html",id);
                page = creation_page_web(nom);
                fprintf(page,
                    "<!DOCTYPE html>\n"
                    "<html lang=\"fr\">\n"
                    "<head>\n"
                    "    <meta charset=\"UTF-8\">\n"
                    "    <title>%s</title>\n"
                    "    <link rel=\"stylesheet\" href=\"style.css\">\n"
                    "    <link rel=\"stylesheet\" href=\"chance.css\">\n"
                    "    <script src=\"chance.js\" defer> </script>"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "    <div id=\"cranedelalose\"></div>"
                    "    <div id=\"youpi-container\"></div>"
                    "    <div class=\"chance-container\">"
                    "       <div id=\"chance-bar\" class=\"chance-bar\">Bravoure chevaleresque</div>"
                    "    </div>"
                    "</body>\n",
                    title, title
                );
            }
        }

        else if (page != NULL) {

            if (strstr(line, "<p>")==line) {
                creation_paragraphe(page, line);
            }

            else if (strstr(line, "<choice")==line) {
                fprintf(page, "<div class=\"choices-row\">\n");
                creation_choix(page,line);
                fprintf(page, "</div>\n");
            }
        }
    }
    printf("page crée");
    return 0;
}

