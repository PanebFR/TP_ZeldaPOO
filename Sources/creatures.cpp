#include "creatures.h"
#include "link.h"
Creatures::Creatures()
{
    this->setZValue(Z_MONSTRE);
    this->setNumeroIcone(ICONE0);
}
Creatures::~Creatures()
{
}
int Creatures::getHealth(){
    return this->_health;
}
void Creatures::setHealth(int p){
    this->_health = p;
}

void Creatures::setDamage(int p){
    this->_damage = p;}
int Creatures::getDamage(){
    return this->_damage;
}

int Creatures::type()const {
    return TYPE_MONSTRE;
}
int Creatures::mouvementOk(){
    QList<QGraphicsItem *> liste = collidingItems() ;
    liste.clear();
    liste = this->collidingItems();
    int mesCollision = liste.size();

    for(int i =0; i<mesCollision;i++)
    {
        if(liste.at(i)->type()==TYPE_MAP || liste.at(i)->type()==TYPE_MONSTRE)
            return COLLISION;

    }
    return MOUVEMENTOK;
}

void Creatures::toucherParLeJoueur(){
    QList<QGraphicsItem *> liste = collidingItems() ;
    liste.clear();
    liste = this->collidingItems();
    int mesCollision = liste.size();

    for(int i =0; i<mesCollision;i++)
    {
        if(liste.at(i)->type()==LINK_ATTACK)
          {

            this->updateHealth();
            int provenanceAttaqueX, provenanceAttaqueY;
            provenanceAttaqueX = this->x()-liste.at(i)->x();
            provenanceAttaqueY = this->y()-liste.at(i)->y();
            if(provenanceAttaqueX>0)
            {
                this->setCap(AXE_RIGHT);
                 for(int jump = 0;jump<JUMP;jump++)
                     this->moveRight();
                 if(!this->mouvementOk())
                 {
                     this->moveLeft();
                     for(int jump = 0;jump<JUMP;jump++)
                         this->moveLeft();
                    }
            }
            else if(provenanceAttaqueX<0)
              {
                this->setCap(AXE_LEFT);
                 for(int jump = 0;jump<JUMP;jump++)
                     this->moveLeft();
                 if(!this->mouvementOk())
                 {
                     this->moveRight();
                     for(int jump = 0;jump<JUMP;jump++)
                         this->moveRight();
                    }
            }
            if(provenanceAttaqueY>0)
            {
                this->setCap(AXE_TOP);
                 for(int jump = 0;jump<JUMP;jump++)
                     this->moveTop();
                 if(!this->mouvementOk())
                 {
                     this->moveBot();
                     for(int jump = 0;jump<JUMP;jump++)
                         this->moveBot();
                    }
            }

            else
            {    this->setCap(AXE_BOT);
                 for(int jump = 0;jump<JUMP;jump++)
                     this->moveBot();
                 if(!this->mouvementOk())
                 {
                     this->moveTop();
                     for(int jump = 0;jump<JUMP;jump++)
                         this->moveTop();
                    }

            }


        }
    }

}


int Creatures::getTypeMov(){
    return this->_move;
}

void Creatures::setTypeMov(int p){
    this->_move = p;
}

void Creatures::advance(int phase){


    if(phase)
    {
        int monMov = this->getTypeMov();
        if(monMov==NEW_MOVE || this->getNbDecalage()>COLLISION_MAX)
        {
            int direction = rand()%AXES_MOUVEMENTS;
            this->setCap(direction);
            this->setTypeMov(SAME_MOV);
            this->setNbDecalage(COLLISION_NULL);

            this->miseAjourIcone(this->getCap());

        }
        else
           {
            monMov = monMov-ONE_MOVE;
            this->setTypeMov(monMov);
            this->miseAjourIcone(this->getCap());
        }

        this->toucherParLeJoueur();
        if(this->getAlive()==DEAD)
        {
            this->hide();
            if(this->getCoeur()==HEART){
                QList <QGraphicsItem*> liste = this->scene()->items();
                for(int i = 0; i<liste.size();i++)
                {
                    if(liste.at(i)->type()==TYPE_MAP_ITEM_COEUR)
                    {
                        liste.at(i)->setPos(this->pos());
                        liste.at(i)->show();
                        Coeur* p = (Coeur*) &(this->scene()->items().at(i));
                        p->setUtilise(HEART_USED);

                    }
                }


            }


            this->~QGraphicsItem();
            return;
        }
        switch (this->getCap()){
            case AXE_BOT:
                this->moveBot();
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveTop();
                        this->moveLeft();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveRight();
                        this->moveTop();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveBot();
                    }
                break;
            case AXE_LEFT:
                this->moveLeft();
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveRight();
                        this->moveBot();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                      this->moveTop();
                      this->moveRight();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                      this->moveLeft();
                    }
                break;
            case AXE_RIGHT:
                this->moveRight();
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveLeft();
                        this->moveTop();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveBot();
                        this->moveLeft();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveRight();
                    }
                break;
            case AXE_TOP :
                this->moveTop();
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveBot();
                        this->moveRight();
                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveLeft();
                        this->moveBot();

                    }
                    if(!this->mouvementOk())
                    {
                        this->uneCollision();
                        this->moveTop();
                    }
                break;
            default:

                break;
        }
}
}



bool Creatures::getAlive(){
    return this->_isAlive;
}

void Creatures::setAlive(bool p){
    this->_isAlive = p;
}

void Creatures::updateHealth(){
    this->_health = this->_health - COUP;
    if(!(this->_health)&&this->_isAlive)
        setAlive(DEAD);
}

void Creatures::setNbDecalage(int p){
    this->_nbDecalage =p;
}

int Creatures::getNbDecalage(){
    return this->_nbDecalage;
}

void Creatures::uneCollision(){
    this->_nbDecalage=(this->_nbDecalage+1);
}

int Creatures::getCoeur(){
    return this->_coeur;
}

void Creatures::setCoeur(int p){
    this->_coeur = p;
}
