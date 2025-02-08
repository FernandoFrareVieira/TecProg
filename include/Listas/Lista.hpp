#pragma once

namespace Listas
{
    template<class TL>
    class Lista
    {
    public:
        Lista():
            pPrimeiro(nullptr),
            tamanho(0)
        {}

        ~Lista()
        {
            limpar();
            pPrimeiro = nullptr;
        }

        template<class TE>
        class Elemento
        {
        private:
            Elemento<TE>* pProximo;
            TE* pInfo;
        public:
            Elemento():
                pProximo(nullptr),
                pInfo(nullptr)
            {}

            ~Elemento()
            {
                if (pInfo)
                    delete pInfo;
                pInfo = nullptr;
            }

            void setProximo(Elemento<TE>* proximo)
            {
                pProximo = proximo;
            }

            Elemento<TE>* getProximo()
            {
                return pProximo;
            }

            void setInfo(TE* info)
            {
                pInfo = info;
            }

            TE* getInfo() 
            {   
                return pInfo;
            }
        };

        template <class TE>
        class Iterator {
        private:
            Elemento<TE>* pAtual;
        public:
            Iterator(Elemento<TE>* inicial = nullptr):
                pAtual(inicial)
            {}

            ~Iterator() {}

            Iterator& operator++() {
                if (pAtual) {
                    pAtual = pAtual->getProximo();
                }
                return *this;
            }

            Iterator operator++(int) {
                Iterator temp = *this;
                if (pAtual) {
                    pAtual = pAtual->getProximo();
                }
                return temp;
            }

            bool operator==(const Elemento<TE>* pElem) const {
                return (pAtual == pElem);
            }

            bool operator!=(const Elemento<TE>* pElem) const {
                return (pAtual != pElem);
            }

            void operator=(const Elemento<TE>* pElem) {
                pAtual = pElem;
            }

            TE* operator*() {
                if (pAtual) {
                    return pAtual->getInfo();
                }
                return nullptr;
            }

            Elemento<TE>* getAtual() const {
                return pAtual;
            }
        };

    private:
        Elemento<TL>* pPrimeiro;    
        int tamanho;

    public:
        Iterator<TL> getPrimeiro() 
        {
            return Iterator<TL>(pPrimeiro);
        }
        
        void incluir(TL* elemento)
        {
            if (!elemento)
                return;

            Elemento<TL>* pE = new Elemento<TL>;
            if (pE) {
                pE->setProximo(pPrimeiro);
                pE->setInfo(elemento);
                pPrimeiro = pE;
                tamanho++;
            }
        }

        void remover(TL* elemento) 
        {
            if (!elemento || !pPrimeiro || tamanho == 0)
                return;

            Iterator<TL> it = getPrimeiro();
            Elemento<TL>* anterior = nullptr;

            while (it.getAtual() && it.getAtual()->getInfo() != elemento) {
                anterior = it.getAtual();
                ++it;
            }

            if (it.getAtual()) { 
                Elemento<TL>* aRemover = it.getAtual();
                if (anterior) {
                    anterior->setProximo(aRemover->getProximo());
                } else {
                    pPrimeiro = aRemover->getProximo(); 
                }

                delete aRemover;
                tamanho--;
            }
        }

        void limpar()
        {
            Elemento<TL>* temp = nullptr;

            while (pPrimeiro) {
                temp = pPrimeiro;
                pPrimeiro = pPrimeiro->getProximo();
                if (temp) {
                    delete temp;
                }
            }

            pPrimeiro = nullptr;
            tamanho = 0;
        }

        const int getTamanho()  
        {   
            return tamanho;
        }

        TL* operator[](int pos)
        {
            if (pos < 0 || pos >= tamanho) {
                return nullptr; 
            }

            Elemento<TL>* atual = pPrimeiro;
            for (int i = 0; i < pos; i++) {
                atual = atual->getProximo();
            }

            return atual->getInfo();
        }
    };
}