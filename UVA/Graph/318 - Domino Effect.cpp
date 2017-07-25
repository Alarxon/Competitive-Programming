//Number 9
#include <bits/stdc++.h>

using namespace std;

int grafo[501][501];

int main()
{
 int n,m,cont=0;
  while(scanf("%d %d", &n, &m)){ //Leemos el numero de las piezas principales (los nodos) y las uniones
    int a[501*501];
    int b[501*501];
    int c[503*501];
    if(n==0 && m==0){
        break; //Si ambos son 0, break
     }
     for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                grafo[i][j]=0; //Se pone 0, en las posiciones iguales porque en este problema los nodos no puden tener union consigo mismo
            }else{
                grafo[i][j]=99999999; //Si no se pone con cualquier numero que sea mas grande que el maximo que te pueda meter
				}
			}
		}


    for(int i=0; i<m; i++){
			scanf("%d %d", &a[i],&b[i]); //Leemos las uniones, la union se da entre el nodo "a" y el nodo "b", los vamos guardando ene l arreglo

			scanf("%d",&c[i]); //Leemos el tiempo
			grafo[a[i]][b[i]]=c[i]; //Utilizamos una matriz para ir gurdando en la posicion de las uniones su tiempo, para asi hacer el grafo (una matriz de adyacencia, siendo el peso el tiempo)
			grafo[b[i]][a[i]]=c[i];
     }

		/*No siempre te daran todas las conecciones, pero todos deben estar conectados porque necesitamos conocer el peso
		  total entre el nodo 1 y el ultimo para calcular el tiempo final en que tarda en caer el ultimo domino.
		  Asi que lo se tiene que hacer es con un algoritmo de busqueda basicamente calcualar cuanto seria el peso entre nuestro punto y el que
		  queremos usando los puntos que ya nos dio el usuario */
		for(int k=1; k<=n; k++){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=n; j++){
					if(grafo[i][j] < grafo[i][k]+grafo[k][j]){
                        grafo[i][j] = grafo[i][j];
					}else{
					    grafo[i][j] = grafo[i][k]+grafo[k][j];
					}
				}
			}
		}

		//Ahora teniendo bien ya nuestro grafo totalmente comunicado. Necesitamos calcular el tiempo y donde caeria
		double tiempo=0;
		int x,y,checador=0;
		for(int i=0; i<m; i++){ /*Vamos a recorrer los par de nodos que nos dio el usario, checando todos y siempre guardando el mayor,
                                  al final el mas mayor sera el peso del ultimo o ultimos dominos*/

			int nodoA=a[i]; //Gurdamos el numero de ambos nodos que nos dieron al inicio en variables para que sea mas facil
			int nodoB=b[i];
			int pesoA=grafo[1][nodoA]; //Tambien guardamos el peso total o tiempo que tarada desde el nodo 1 hasta ese nodo, se hace con ambos
			int pesoB=grafo[1][nodoB];
			int pesoNodos=c[i]; //Guardamos el peso entre esos dos nodos
			double t; //Para guardar el tiempo, es double porque puede dar con punto decimal
			int minimo, maximo;

			//Guardamos cual es el mayor y cual es el menor de los dos nodos en cuanto a su peso que se tarda en llegar a el
			if(pesoA < pesoB){
                minimo = pesoA;
			}else{
			    minimo = pesoB;
			}

			if(pesoA > pesoB){
                maximo = pesoA;
			}else{
			    maximo = pesoB;
			}

            /*Ahora, puede haber dos casos, uno donde el ultimo domino que cae, cae en un nodo (porque aparte de la comunicacion con el otro nodo esta solo,
              o que el tiempo en que tarda en llegar a un nodo desde el primer es mayor o igual que el tiempo que tarda en recorrer el otro nodo desde el incio
              hasta el final ), o que el ultmo nodo en caer esta entre dos nodos(porque ambos estan conectando directamente con con otros nodso que lo llevan hasta el primero) */
			if(minimo+pesoNodos<=maximo){ /*Si sumando el peso menor de los dos, mas el peso entre esos dos nodos es menor o igual que el peso del nodo mayor
                                            significa que por ende el nodo menor esta solo y caera en el*/

				t=minimo+pesoNodos; //En este caso el tiempo solo es el minimo mas el peso de los nodos
				if(t>tiempo){ //Solo vamos guardando los datos si es mayor que nuestra variable tiempo que va acumulando el mayor tiempo
					checador=1;
					tiempo=t;
					if(pesoA<=pesoB){
                        x=nodoB;
					}else{
                        x=nodoA;
					}
				}
			}else{

				t=maximo+(pesoNodos-abs(pesoA-pesoB))/2.00; /*En el caso de termine el ultimo domino entre dos nodos, entonces la formula para sacar el peso
				                                            total es el peso del maximo(porque realmente el del menor no importa ese llegara antes y
                                                            no afecta al resultado) mas el peso entre los nodos menos el tiempo que se tardan en llegar ambos
                                                            entre dos porque es a la mitad del camino entre esos dos nods */
				if(t>tiempo){
					checador=0;
					tiempo=t;
					x=nodoA; y=nodoB;
				}
			}

		}

		 cont++;
		 printf("System #%d\n",cont);
		 if(m==0){ //En el caso de que m es 0 signfiica que jamaz entro al for y que solo hay un domino afuerzas
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n");
        }else{
			if(checador==0){ //Si checador es 0 entonces callo entre dos nodos el domino, y pues se imprime el tiempo y ambos nodos
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",tiempo,x,y);
			}else{ //Si el checador noes 0, osea es 1, entonces callo al final de un nodo, solo se imrpime el tiempo y ese nodo
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n",tiempo,x);
			}
		}
        printf("\n");
	}
	return 0;
}
