class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int esquerda = 0, direita = n-1;
        int area = 0;

        while(esquerda < direita){
            int largura = direita - esquerda;
            int menor_altura = min(height[esquerda], height[direita]);

            area = max(area, largura*menor_altura);
            if(height[esquerda] < height[direita])
                esquerda++;
            else
                direita--;
        }
        return area;
    }
};