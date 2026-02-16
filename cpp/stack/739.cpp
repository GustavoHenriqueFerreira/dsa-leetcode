class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> resultado(n, 0);

        stack<int> stack;
        for (int i = 0; i < n; i++) {
            // parte mais importante é o while pra ir repetindo com o top menor que
            // a temperatura atual
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]){
                int indice = stack.top(); // pega o indice do valor a ser atualizado no resultado
                stack.pop(); // tira por que acho maior na sequencia do array
                resultado[indice] = i - indice; // atualiza os dias para achar maior com o indice
            }
            
            stack.push(i);
        }

        return resultado;
    }
};