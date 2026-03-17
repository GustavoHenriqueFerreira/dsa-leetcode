class LRUCache {
public:

    int cap; 
    // capacidade máxima do cache

    list<pair<int,int>> cache;
    // lista que guarda (key, value)
    // frente da lista = mais recentemente usado
    // final da lista = menos recentemente usado

    unordered_map<int, list<pair<int,int>>::iterator> mp;
    // hashmap que mapeia:
    // key -> posição dessa chave dentro da lista

    LRUCache(int capacity) {
        cap = capacity;
        // inicializa a capacidade do cache
    }

    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;
        // se a chave não existe no mapa, retorna -1

        auto node = *mp[key];
        // pega o par (key,value) que está na lista

        cache.erase(mp[key]);
        // remove o nó da posição atual na lista
        // porque vamos mover ele para frente

        cache.push_front(node);
        // coloca o nó no início da lista
        // agora ele é o mais recentemente usado

        mp[key] = cache.begin();
        // atualiza no mapa a nova posição da chave
        // (que agora é o início da lista)

        return node.second;
        // retorna o valor associado à chave
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }
        // se a chave já existe:
        // removemos ela da lista
        // (vamos reinserir atualizada)

        cache.push_front({key,value});
        // adiciona o novo par (key,value) no início
        // ele vira o mais recentemente usado

        mp[key] = cache.begin();
        // salva no mapa a posição desse novo nó

        if(cache.size() > cap) {
            // se o cache ultrapassou a capacidade

            auto last = cache.back();
            // pega o último elemento da lista
            // que é o menos recentemente usado

            mp.erase(last.first);
            // remove essa chave do hashmap

            cache.pop_back();
            // remove o último nó da lista
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */