#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{

    vector<pair<string, int>> grupoCriancas;
    int qtdCriancas{-1};

    while (true)
    {

        cin >> qtdCriancas;
        if (qtdCriancas == 0)
            break;
        for (int i = 0; i < qtdCriancas; i++)
        {
            // stringstream nome;
            // cin >> nome; Não há operador definido para >> stringstream

            string nome;
            int valor{0};
            cin >> nome;
            cin >> valor;
            // cout << "Nome: " << nome << " Valor: " << valor << "\n";
            pair crianca = make_pair(nome, valor);
            grupoCriancas.push_back(crianca);
            // cout << "Nome: " << grupoCriancas[0].first << " Valor: " << grupoCriancas[0].second << "\n";
        }

        auto criancaInicialIterator = grupoCriancas.begin();
        int numSelecionado = criancaInicialIterator->second;
        int indexPerdedor = 0;
        while (!(grupoCriancas.size() == 1))
        {
            //cout << "Tamanho: " << grupoCriancas.size() << endl;
            cout << "--- Novo jogo ---" << endl;
            cout << "Jogador inicial: " << criancaInicialIterator->first << " " << criancaInicialIterator->second << endl;

            for (auto &crianca : grupoCriancas)
            {
                cout << "--"<< crianca.first << " " << crianca.second << endl;
            }
            
            
            //Se o num selecionado for par
            if(numSelecionado % 2 ==0)
                indexPerdedor =(numSelecionado + (criancaInicialIterator - grupoCriancas.begin())) % grupoCriancas.size();

            //Se o num selecionado for impar
            else
                indexPerdedor = ((criancaInicialIterator - grupoCriancas.begin()) - numSelecionado) $ grupoCriancas.size();

            auto perdedorIterator = grupoCriancas.begin() + indexPerdedor;
            numSelecionado = perdedorIterator->second;

            cout << "Perdedor: " << perdedorIterator->first << endl;

            criancaInicialIterator = grupoCriancas.erase(perdedorIterator);
        }

        cout << "Vencedor(a): " << grupoCriancas.front().first << endl;
        grupoCriancas.clear();
    }
}
