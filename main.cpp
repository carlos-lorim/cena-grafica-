
/* 
 * Autor: carlos augusto regis lorim 
 * ra: 2024.1.08.004
 * trabalho 3 de AEDs pratica
 * 
 * esse codigo tem a funcao de ler formas de um arquivo .txt e calcular areas ou volumes. 
 */



#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ifstream arquivo("cenegrafia.txt"); // Abre o arquivo

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1; // Retorna um código de erro
    }



    //!!! o as medidas das formas 3d devem seguir a ordem das variaveis !!!

    // variaveis
    string forma;
    float l1, l2, l3; // usado para as formas 2d 
    float raio, altura; // usados no cilindro 
    float comprimento, largura, alt; //usados no parelelepipedo 
    float base, alt2; // usado no cone 
    float aresta; //usado no cubo 
    float raio2; //usada na esfera 

    // Loop para ler cada linha do arquivo
    while (arquivo >> forma) {

        if (forma == "fim") {
            break;
        }




        // triangulos 
        if (forma == "triangulo") {
            arquivo >> l1 >> l2 >> l3;

            // verifica se e triangulo
            if (l1 + l2 < l3 || l2 + l3 < l1 || l3 + l1 < l2) {
                cout << "as medidas nao formao triangulo " << endl;
            } else {
                float semiPerimetro = (l1 + l2 + l3) / 2;
                float area = sqrt(semiPerimetro * (semiPerimetro - l1) * (semiPerimetro - l2) * (semiPerimetro - l3));
                // descreve a forma 
                cout << "a forma è um :" << forma << "  || sua area è: " << area << endl;
            }


        }//quadrado 
        else if (forma == "quadrado") {
            arquivo >> l1;
            float area = (l1 * l1);
            //descreve a forma 
            cout << "a forma è um :" << forma << " || sua area è: " << area << endl;
        }     
        //retangulo
        else if (forma == "retangulo") {
            arquivo >> l1 >> l2;

            //verifica se forma retangulo 
            if (l1 == l2) {
                cout << "as medidas nao formao retangulo " << endl;
            } else {

                float area = (l1 * l2);
                //descreve a forma 
                cout << "a forma è um :" << forma << "  || sua area è: " << area << endl;
            }
        }            // circulo 
        else if (forma == "circulo") {
            arquivo >> l1; // l1 nesse caso è o raio 
            float area = (M_PI * (l1 * l1));
            //descreve a forma 
            cout << "a forma è um :" << forma << " || sua area è: " << area << endl;
        }

        // cilindro 
        if (forma == "cilindro") {
            arquivo >> raio>> altura;
            if (raio < 1 || altura < 1) {
                cout << "as medidas nao formao cilindro" << endl;
            } else {
                float volume = (M_PI * (raio * raio) * altura);
                //descreve a forma 
                cout << "a forma è um :" << forma << " || seu volume è: " << volume << endl;
            }
        }

        // paralelepipedo
        if (forma == "paralelepipedo") {
            arquivo >> comprimento >> largura>> alt;
            if (comprimento < 1 || largura < 1 || alt < 1) {
                cout << "as medidas nao formao paralelepipedo" << endl;
            } else {

                float volume = (comprimento * altura * largura);
                //descreve a forma 
                cout << "a forma è um:" << forma << " || seu volume è: " << volume << endl;
            }
        }

        // cone 
        if (forma == "cone ") {
            arquivo >> base >> alt2;

            if (base < 1 || alt2 < 1) {
                cout << "as medidas nao formao cone " << endl;
            } else {

                float volume = (base * altura / 3);
                //descreve a forma 
                cout << "a forma è um:" << forma << " || seu volume è: " << volume << endl;
            }
        }

        // cubo 
        if (forma == "cubo") {
            arquivo >> aresta;

            if (aresta < 1) {
                cout << "as medidas nao formao cubo " << endl;
            } else {

                float volume = (aresta * aresta * aresta);
                //descreve a forma 
                cout << "a forma è um:" << forma << " || seu volume è: " << volume << endl;
            }
        }

        // esfera
        if (forma == "esfera") {
            arquivo >> raio2;

            if (raio2 < 1) {
                cout << "as medidas nao formao esfera " << endl;
            } else {

                float volume = (4 * M_PI * raio2 * raio2 * raio2 / 3);
                //descreve a forma 
                cout << "a forma è uma :" << forma << "  || seu volume è: " << volume << endl;

            }
        }
    }

    return 0;
}
