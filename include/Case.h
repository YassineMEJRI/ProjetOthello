#ifndef CASE_H
#define CASE_H


class Case
{
    public:
        Case(const int i  , int c);
        Case();
        int getCouleur () ;
        void setCouleur (int couleur );
        int getId () const ;
        static int getCompteurId();
        virtual ~Case();


    protected:

    private:
        int id ;
        int couleur ;// -1 vide 0 blanc 1 noir
        static  int compteurId ;

};

#endif // CASE_H
