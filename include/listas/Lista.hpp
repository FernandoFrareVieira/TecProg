namespace Listas
{
    template<class TL>
    class Lista
    {
        private:
            Elemento<TL> pPrimeiro;
            int tamanho;

        public:
            Lista():
                pPrimeiro(nullptr),
                tamanho(0)
            {}

            ~Lista()
            {
                clear();
                pPrimeiro = nullptr;
            }

            void incluir(TL* elemento)
            {
                if(pE) {
                    Elemento<TL>* pE = new Elemento<TL>;

                    pE->setInfo(elemento);
                    pE->setProximo(pPrimeiro);

                    pPrimeiro = pE;
                    tamanho = tamanho + 1;
                }
            }

            void limpar()
            {
                Elemento<TL>* temp = nullptr;

                for(int i = 0; i < getTamanho(); i++) {
                    temp = pPrimeiro;
                    pPrimeiro = pPrimeiro->getProximo();
                    if(temp) {
                        delete temp;
                    }
                }

                pPrimeiro = nullptr;
                tamanho = 0;
            }

            const int getTamanho() const 
            {
                return tamanho;
            }

            template<class TE>
            class Elemento
            {
                private:
                    Elemento* <TE> pProximo;
                    TE* pInfo;
                public:
                    Elemento():
                        pProximo(nullptr),
                        pInfo(NULL)
                    {}

                    ~Elemento()
                    {}

                    void setProximo(Elemento<TE>* proximo)
                    {
                        pProximo = proximo;
                    }

                    Elemento<TE>* getProximo() const  
                    {
                        return pProximo;
                    }

                    void setInfo(TE* info)
                    {
                        pInfo = info;
                    }

                    TE* getInfo() const
                    {
                        return pInfo;
                    }
            };


    };
}