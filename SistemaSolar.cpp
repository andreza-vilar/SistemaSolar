/*>Discente: Andreza Vilar de Farias
>Matrícula: 120210357
>Período: 2021.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 02
>Professor: Marcus Salerno
>Unidade 2 : lvp 5*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct CorpoCeleste{
    string nome;
    double raioPlaneta;
    double massa;

};



class Sistema_Interestelar{
	const double constGravitacional = 6.67e-11;
	string nome;
	CorpoCeleste Corpo1;
	CorpoCeleste Corpo2;
	double distanciaCorposCelestes;

    public:
		void setPlanetas(CorpoCeleste, CorpoCeleste);
		void setDistanciaCorposCelestes(double);
		double forcaGravitacional();
		float velocidadeEmOrbita();
		float velocidadeDeEscape();
		float campoGravitacional();

};


void Sistema_Interestelar :: setPlanetas(CorpoCeleste Planeta1, CorpoCeleste Planeta2){
    Corpo1 = Planeta1;
    Corpo2 = Planeta2;
}


void Sistema_Interestelar :: setDistanciaCorposCelestes(double distancia){
	distanciaCorposCelestes = distancia;

}


double Sistema_Interestelar :: forcaGravitacional(){
    return (constGravitacional*Corpo1.massa*Corpo2.massa) / (pow(distanciaCorposCelestes,2));

}

float Sistema_Interestelar :: velocidadeEmOrbita() {
	if (Corpo1.massa >= Corpo2.massa)
        return (sqrt((constGravitacional * Corpo1.massa) / distanciaCorposCelestes)) / 1000;

    else
        return (sqrt((constGravitacional * Corpo2.massa) / distanciaCorposCelestes)) / 1000;

}

float Sistema_Interestelar :: velocidadeDeEscape(){
	if (Corpo1.massa >= Corpo2.massa)
	    return (sqrt((2 * constGravitacional * Corpo1.massa) / Corpo1.raioPlaneta)) / 1000;

	else
	    return (sqrt((2 * constGravitacional * Corpo2.massa) / Corpo2.raioPlaneta)) / 1000;

}


float Sistema_Interestelar :: campoGravitacional(){
	if (Corpo1.massa >= Corpo2.massa)
		return (constGravitacional * Corpo1.massa) / (pow(Corpo1.raioPlaneta,2));
	else
		return (constGravitacional * Corpo2.massa) / (pow(Corpo2.raioPlaneta,2));

}

int main (){
	setlocale(LC_ALL,"Portuguese");

	Sistema_Interestelar Sistema_Solar;
	CorpoCeleste PlanetaAux, PlanetaAux2;
	double distancia;

	cout<<"Preencha os dados para os dois corpos celestes..."<<endl<<"Corpo 1"<<endl<<"Nome:"<<endl;
	cin >>PlanetaAux.nome;
	cout<<"Massa:";
	cin >>PlanetaAux.massa;
	cout<<"Raio:";
	cin >>PlanetaAux.raioPlaneta;

	cout<<endl<<"Corpo 2"<<endl<<"Nome:";
	cin >>PlanetaAux2.nome;
	cout<<"Massa:";
	cin >>PlanetaAux2.massa;
	cout<<"Raio:";
	cin >>PlanetaAux2.raioPlaneta;
	cout<<endl;
	cout<<"Distância entre os corpos: ";
	cin >> distancia;


	Sistema_Solar.setDistanciaCorposCelestes(distancia);
	Sistema_Solar.setPlanetas(PlanetaAux, PlanetaAux2);

	cout<<endl<<": "<<scientific<<setprecision(2);
    cout<<endl<<"A força gravitacional é: "<< Sistema_Solar.forcaGravitacional()<<"N";
    cout<<endl<<"O campo gravitacional do maior corpo celeste é: "<<Sistema_Solar.campoGravitacional()<<"m/s²";
    cout<<endl<<"A velocidade de escape do maior corpo é: "<<Sistema_Solar.velocidadeDeEscape()<<"km/s";
    cout<<endl<<"A velocidade em orbita do menor corpo em relação ao maior é: "<<Sistema_Solar.velocidadeEmOrbita()<<"km/s";


	return 0;
}