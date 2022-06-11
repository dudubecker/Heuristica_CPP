#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Função para printar vetores

void print(std::vector<int> const &input)
{
    for (auto const &i: input) {
        cout << i << " ";
    }
}

int main(){
	
	/* Dados da instância */
	
	// Coordenadas x de cada nó i da instância
	vector <double> x {25.0, 19.942, 13.131, 41.105, 29.622, 20.387, 8.195, 39.947, 32.184, 46.07, 15.395, 38.336, 49.706, 17.748, 42.549, 44.178, 26.591, 3.855, 37.401, 45.989, 35.511, 39.026, 28.364, 40.399, 42.439, 48.019, 35.573, 36.158, 43.76, 13.387, 21.442, 4.515, 14.379, 17.381, 43.627, 0.062, 42.389, 6.799, 24.429, 44.972, 30.09, 17.571, 30.378, 20.594, 19.93, 5.808, 0.497, 43.952, 13.843, 19.524, 30.948, 25.0};
	
	// Coordenadas y de cada nó i da instância
	vector <double> y {25.0, 16.269, 45.499, 42.288, 23.653, 33.75, 24.765, 22.762, 39.039, 49.15, 23.92, 13.008, 28.635, 22.292, 29.924, 9.661, 36.243, 9.895, 26.569, 20.442, 15.228, 12.034, 23.084, 46.524, 43.835, 11.272, 46.733, 11.897, 46.624, 36.048, 34.131, 24.464, 35.446, 24.472, 19.724, 49.145, 13.101, 22.468, 6.787, 41.699, 18.098, 39.599, 32.49, 9.692, 25.913, 45.172, 25.269, 38.259, 16.968, 12.881, 13.248, 25.0};
	
	// Tempo de serviço de cada nó i da instância
	vector <double> d {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	
	// Demanda de cada nó i da instância
	vector <double> q {0.0, 7.0, 9.0, 15.0, 5.0, 12.0, 5.0, 10.0, 8.0, 11.0, 12.0, 8.0, 14.0, 15.0, 8.0, 11.0, 11.0, 5.0, 11.0, 7.0, 10.0, 13.0, 10.0, 10.0, 14.0, 10.0, -7.0, -9.0, -15.0, -5.0, -12.0, -5.0, -10.0, -8.0, -11.0, -12.0, -8.0, -14.0, -15.0, -8.0, -11.0, -11.0, -5.0, -11.0, -7.0, -10.0, -13.0, -10.0, -10.0, -14.0, -10.0, 0.0};
	
	// Início da janela de tempo de cada nó i da instância
	vector <double> e {0.0, 175.0, 522.0, 256.0, 529.0, 469.0, 436.0, 517.0, 414.0, 28.0, 96.0, 169.0, 54.0, 423.0, 112.0, 511.0, 36.0, 24.0, 293.0, 402.0, 496.0, 477.0, 299.0, 267.0, 61.0, 410.0, 209.0, 562.0, 261.0, 549.0, 470.0, 439.0, 545.0, 434.0, 57.0, 125.0, 173.0, 97.0, 439.0, 124.0, 527.0, 45.0, 58.0, 316.0, 428.0, 538.0, 517.0, 320.0, 306.0, 99.0, 427.0, 0.0};
	
	// Fim da janela de tempo de cada nó i da instância
	vector <double> l {1000.0, 235.0, 582.0, 316.0, 589.0, 529.0, 496.0, 577.0, 474.0, 88.0, 156.0, 229.0, 114.0, 483.0, 172.0, 571.0, 96.0, 84.0, 353.0, 462.0, 556.0, 537.0, 359.0, 327.0, 121.0, 470.0, 269.0, 622.0, 321.0, 609.0, 530.0, 499.0, 605.0, 494.0, 117.0, 185.0, 233.0, 157.0, 499.0, 184.0, 587.0, 105.0, 118.0, 376.0, 488.0, 598.0, 577.0, 380.0, 366.0, 159.0, 487.0, 1000.0};
	
	// Número de pedidos
	int n {25};
	
	// Capacidade de cada veículo
	int Cap {15};
	
	// Definindo vetor com "t_ij", para cada par de nós i j:
	
	// Inicializando o vetor com valores iguais a 0
	vector<vector<double>> t(2*n + 2, vector<double> (2*n + 2, 0));
	
	// Atribuindo distâncias t_ij para cada elemento
	for(int i = 0; i < 2*n + 2; i++)
	{
		for(int j = 0; j < 2*n + 2; j++)
		{
			// Calculando distância e atribuindo à variável
			t[i][j] = floor(sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j],2))*100.0)/100.0;
		}
	}
	
	/* Criando variáveis com valores atualizados a cada inserção */
	
	// Pedidos não atendidos
	vector <int> L (n, 0);
	for(int value = 1, index = 0; value < n + 1; value++, index++){
		L[index] = value;
	}
	
	// Solução com rotas, iniciando com uma rota vazia
	vector<vector <int>> S {{0, 2*n + 1}};
	
	// Quantidade de requests atendidos (inicia-se em 0)
	int qtd_atendidos {0};
	
	/* Início do processo de inserção, que se finda quando todos os pedidos são atendidos */
	
	while (qtd_atendidos < n){
		
		// Variável que abrigará o request a ser inserido na iteração
		int request {L.at(0)};
		
		// Índice do nó de pickup correspondente ao request
		int no_pickup {request};
		
		// Índice do nó de delivery correspondente ao request
		int no_delivery {request + n};
		
		// Vetor que guardará o delta mínimo de incremento da função objetivo para cada rota presente na solução com nova inserção
		vector <double> deltas_minimos;
		
		// Vetor de duas dimensões que guardará a rota correspondente ao delta mínimo para cada rota presente na solução
		vector <vector<int>> rotas_delta_minimo;
		
		// Variável que controlará o número de rotas factíveis encontradas
		int num_rotas_factiveis {0};
		
		// Para cada rota da solução, serão testadas todas as posições de inserção possíveis (rotas criadas paralelamente)
		for (unsigned index_rota {0}; index_rota < S.size(); index_rota++){
			
			// Criando vetor "rota" para armazenar a rota com índice correspondente à iteração
			vector <int> rota {S.at(index_rota)};
			
			// Variável para controlar o delta mínimo para cada rota (variações no valor da função objetivo dados pela inserção de um novo request na rota)
			double delta_minimo {100000};
			
			// Variável que guardará a rota com delta mínimo gerada na iteração pelas inserções
			vector <int> rota_delta_minimo;
			
			// Testando inserções possíveis, avaliando factibilidade e, se a solução for factível, calculando delta
			for (unsigned pos_insercao_no_pickup {1}; pos_insercao_no_pickup < rota.size() + 1; pos_insercao_no_pickup++){
				
				for (unsigned pos_insercao_no_delivery {1}; pos_insercao_no_delivery < rota.size() + 1; pos_insercao_no_delivery++){
					
					// Testando apenas índices de inserção válidos: índice de delivery maior do que o de pickup (precedence) e diferente dele!
					// A iteração começa em 1 e termina no tamanho da rota porque não se considera a primeira e última posição da rota, que são o depósito
					if ((pos_insercao_no_pickup != pos_insercao_no_delivery) and (pos_insercao_no_pickup < pos_insercao_no_delivery)){
						
						// Criando uma variável para testar as inserções (alterações em "rota_teste" não implicarão alterações em "rota")
						vector <int> rota_teste = rota;
						
						// Inserindo nós na rota, nas posições da iteração
						
						rota_teste.insert(rota_teste.begin() + pos_insercao_no_pickup, no_pickup);
						rota_teste.insert(rota_teste.begin() + pos_insercao_no_delivery, no_delivery);
						
						// *** Checando factibilidade da rota ***
						// *OBS: não é necessário testar pairing e precedence, porque os pedidos são inseridos em pares nas rotas e as posições de inserção já asseguram precedência
						
						// Variável booleana, que controla a factibilidade
						bool factivel = true;
						
						// Capacidade atual do veículo na rota (inicia como 0)
						double cap_atual {0};
						
						// Tempo atual da rota (inicia como 0)
						double t_atual {0};
						
						// Para cada nó da rota teste
						for (unsigned index_rota_teste {1}; index_rota_teste < rota_teste.size(); index_rota_teste++){
							
							// Variável que guarda o nó atual considerado na checagem de factibilidade
							int no_atual {rota_teste.at(index_rota_teste - 1)};
							
							// Variável que guarda o nó seguinte considerado na checagem de factibilidade
							int no_seguinte {rota_teste.at(index_rota_teste)};
							
							// Checando se ir do no atual para o nó seguinte irá violar as restrições de capacidade e time window
							if ((cap_atual + q.at(no_seguinte) > Cap) || (l.at(no_seguinte) < t_atual + t.at(no_atual).at(no_seguinte))){
								
								// Atribuindo valor falso para a variável de factibilidade e quebrando o laço for
								factivel = false;
								break;
								
							// Caso seja possível, os valores são atualizados
							} else {
								// Atualizando valores
								
								// Capacidade
								cap_atual += q.at(no_seguinte);
								
								// Tempo
								// Caso haja adiantamento (tempo de chegada menor que a janela de tempo de abertura)
								if (t_atual + t.at(no_atual).at(no_seguinte) < e.at(no_seguinte)){
									t_atual = e.at(no_seguinte);
									
								} else {
									t_atual += t.at(no_atual).at(no_seguinte);
									
								}
							}
						}
						// Caso a solução seja factível, calcula-se o delta
						if (factivel){
							
							// Incrementando número de rotas factíveis encontradas para a rota da iteração
							num_rotas_factiveis += 1;
							
							// Variação da função objetivo pela inserção dos nós nas posições da iteração
							
							// Variação pela inserção do nó de pickup
							double delta_pickup {t[rota_teste[pos_insercao_no_pickup - 1]][rota_teste[pos_insercao_no_pickup]] + t[rota_teste[pos_insercao_no_pickup]][rota_teste[pos_insercao_no_pickup + 1]] - t[rota_teste[pos_insercao_no_pickup - 1]][rota_teste[pos_insercao_no_pickup + 1]]};
							
							// Variação pela inserção do nó de delivery
							double delta_delivery {t[rota_teste[pos_insercao_no_delivery - 1]][rota_teste[pos_insercao_no_delivery]] + t[rota_teste[pos_insercao_no_delivery]][rota_teste[pos_insercao_no_delivery + 1]] - t[rota_teste[pos_insercao_no_delivery - 1]][rota_teste[pos_insercao_no_delivery + 1]]};
							
							// Variação total
							double delta {delta_pickup + delta_delivery};
							
							// Se o delta for menor que o delta mínimo já registrado, atualizam-se os valores de delta mínimo e a rota correspondente
							
							if (delta < delta_minimo){
								delta_minimo = delta;
								rota_delta_minimo = rota_teste;
								
							}
						// Caso contrário, passa-se para a próxima posição de inserção
						} else {
							;
							}
					}
				}
			}
			// Guardando valores de delta mínimo e rota correspondente
			deltas_minimos.push_back(delta_minimo);
			rotas_delta_minimo.push_back(rota_delta_minimo);
			
		}
		// Checando qual das rotas teve o menor incremento na função objetivo
		
		int indice_rota_delta_minimo = min_element(deltas_minimos.begin(),deltas_minimos.end()) - deltas_minimos.begin();
		vector<int> rota_delta_minimo = rotas_delta_minimo.at(indice_rota_delta_minimo);
		
		// Caso tenha sido encontrada ao menos uma posição de inserção factível
		if (num_rotas_factiveis > 0){
			
			S.at(indice_rota_delta_minimo) = rota_delta_minimo;
			
		// Caso contrário, isso significará que não foram encontradas posições de inserção factíveis para as rotas em questão
		// fazendo-se necessária uma nova rota
		
		} else {
			// Rota vazia com os nós da iteração
			vector <int> nova_rota {0, no_pickup, no_delivery, 2*n + 1};
			S.push_back(nova_rota);
		}
		// Atualizando quantidade de pedidos atendidos
		qtd_atendidos += 1;
		
		// Removendo pedido de L
		L.erase(L.begin());
		
	}
	
	/* Printando solução */
	
	for (unsigned index_rota {0}; index_rota < S.size(); index_rota++){
		print(S[index_rota]);
		cout << '\n';
	}
	
	return 0;
}