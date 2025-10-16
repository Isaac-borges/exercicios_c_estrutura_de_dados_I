#include <string>
#include <iostream>

using namespace std;

class No {
    public:
        int matricula_aluno;
        string nome_aluno;
        No *next;

        No (int matricula, string nome){
            matricula_aluno = matricula;
            nome_aluno = nome;
            next=NULL;
        }
}; 

class LinkedList{
    public:
        No *begin, *end;
        long size;
        LinkedList(){
            begin = NULL;
            end = NULL;
            size = 0;
        };

        // void addFirst(int matricula, string nome) {
        //     No *node = new No(matricula, nome);
        //     node->next = this->begin;
        //     this->begin = node;
        //     this->size++;
        // };
        
        void addFirst(int matricula, string nome) {
            No *node = new No(matricula, nome);
            node->next = this->begin;

            if (size == 0) {
                this->end = node;
            }

            this->begin = node;
            this->size++;
        };

        void addLast(int matricula, string nome) {
            No *node = new No(matricula, nome);

            if (begin == NULL) {
                begin = node;
                end = node;
            }
            else {
                this->end->next = node;
                this->end = this->end->next;
            }
            this->size++;
        }

        void print() {
            No *observer = this->begin;

            while (observer != NULL) {
                cout << "Matricula: " << observer->matricula_aluno << "; Nome: " << observer->nome_aluno << "\n";

                observer = observer->next;
            }
        }  

        void search(int matricula) {
            No *observer = this->begin;

            while ((observer != NULL) && (observer->matricula_aluno != matricula)){
                observer = observer->next;
            };
            if (observer == NULL) cout << "\nMatricula nao encontrada!\n";
            else cout << "\nMatricula: " << observer->matricula_aluno << "\nNome do aluno: " << observer->nome_aluno;
        }


        void invert() {
            No *previous = NULL;
            No *current = begin;
            No *next = NULL;

            while (current != NULL) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            
            this->end = this->begin;
            this->begin = previous;
        }
        
        LinkedList *copy(){
            LinkedList *copy = new LinkedList();
            No *observer = this->begin;

            while (observer != NULL) {
                copy->addLast(observer->matricula_aluno, observer->nome_aluno);
                observer = observer->next;
            }

            return copy;
        }

        LinkedList *invertCopy_2n() {
            LinkedList *invertedCopy = this->copy();
            invertedCopy->invert();

            return invertedCopy;
        }

        LinkedList *invertCopy_n(){
            LinkedList *copy = new LinkedList();
            No *observer = this->begin;

            while (observer != NULL) {
                copy->addFirst(observer->matricula_aluno, observer->nome_aluno);
                observer = observer->next;
            }

            return copy;
        }
};

int main() {
    LinkedList *L = new LinkedList();
    L->addLast(1, "Isaac");
    L->addLast(2, "Alvaro");
    L->addLast(3, "Leo");
    L->addLast(4, "Paul");
    L->addLast(5, "Pao");
    L->addLast(6, "Palo");
    L->addLast(7, "ulo");
    L->addLast(8, "lo");
    
    L->print();
    cout << "------------------\n";
    L->invert();
    L->print();

    L->search(1);
    L->search(5);
    L->search(8);
    L->search(10);
    cout << "------------------\n2n\n";
    LinkedList *copy_2n= L->invertCopy_2n(); 
    copy_2n->print();
    cout << "------------------\nL\n";
    L->print();
    cout << "------------------\nn\n";
    LinkedList *copy_n = L->invertCopy_n(); 
    copy_n->print();
    cout << "------------------\n";
    copy_n->addFirst(10, "Nome");
    
    L->print();

    return 0;
}