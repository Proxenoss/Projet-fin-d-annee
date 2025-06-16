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
                    "    <link rel=\"stylesheet\" href=\"mastermind.css\">\n"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "    <button onclick=\"openPopup()\">Résoudre l'égnime</button>"
                    "<div id=\"popup\" class=\"popup\">"
                    "   <div class=\"popup-content\">"
                    "       <h2>Mastermind</h2>"
                    "       <p>Sélectionnez 4 couleurs :</p>"
                    "       <div id=\"color-picker\"></div>"
                    "       <div id=\"current-guess\"></div>"
                    "       <button onclick=\"submitGuess()\">Valider</button>"
                    "       <button onclick=\"closePopup()\">Fermer</button>"
                    "       <pre id=\"feedback\"></pre>"
                    "   </div>"
                    "</div>"
                    "<script src=\"mastermind.js\"></script>"
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
                    "    <link rel=\"stylesheet\" href=\"compteestbon.css\">\n"
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
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
                    "<script src=\"compteestbon.js\"></script>"
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
                    "    <link rel=\"preconnect\" href=\"https://fonts.googleapis.com\">"
                    "    <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin>"
                    "    <link href=\"https://fonts.googleapis.com/css2?family=Quintessential&display=swap\" rel=\"stylesheet\">"
                    "</head>\n"
                    "<body>\n"
                    "    <h1>%s</h1>\n"
                    "    <div class=\"chance-container\">"
                    "       <div id=\"chance-bar\" class=\"chance-bar\">Bravoure chevaleresque</div>"
                    "    </div>"
                    "<script src=\"chance.js\"></script>"
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

