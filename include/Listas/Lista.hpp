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
            pAtual(inicial) {

            }

            ~Iterator() {

            }
            
            Iterator& operator++(){
                pAtual = pAtual->pProximo;  
                return *this;
            }

            Iterator& operator++(int) {
                pAtual = pAtual->getProximo();
                return *this;
            }

            bool operator==(const Elemento<TE>* pElem) const{
                return  (pAtual==pElem);
            }

            bool operator!=(const Elemento<TE>* pElem) const{
                return (pAtual!=pElem);
            }

            void operator=(const Elemento<TE>* pElem) {
                pAtual = pElem;
            }

            TE* operator*() {
                return pAtual->getInfo();
            }

            Elemento<TE>* getAtual() const  {
                return pAtual;
            }
        };
    private:
        Elemento<TL>* pPrimeiro;    
        int tamanho;
    public:
        Iterator<TL> getPrimeiro() {
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

        void limpar()
        {
            Elemento<TL>* temp =  nullptr;

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

    };
}