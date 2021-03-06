#ifndef SMEAR_H
#define SMEAR_H

#include "interface/Event.hpp"

#define SMEAR_OK 0
#define SMEAR_NA 1
#define SMEAR_UNKOWN_FAIL 2

class SmearBase{
    public:

        SmearBase(){};
        ~SmearBase(){};

        // ---
        string name_ = "NONE";
        int syst_;
        const inline string name() {
            if (syst_ == 0 ) return name_;
            else if (syst_ >0 ) return name_ + "Up" ; // this name should be consistent with datacards
            else  return name_ + "Down" ;
        }
        //const inline string operator(){return name();};
        virtual void inline SetSyst(int s){syst_=s;}
        // ---
        virtual int smear(Event *e){return 0;}; // 0 = success; 1 not applicable to the event
        virtual inline vector<Jet*> &GetJets(Event *e){return e->jets_;}
        virtual inline Met &GetMet(Event *e){return e->met_;}
};

class SmearLepSF : virtual public SmearBase
{
    public:
        SmearLepSF() :SmearBase(){ name_= "LEPSF";}
        virtual int smear(Event *e);
};

class SmearJes : virtual public SmearBase
{
    public:
        SmearJes() : SmearBase(){ name_ = "JES";}
        virtual int smear(Event*e);	
};

class SmearJer:virtual public SmearBase
{
    public:
        SmearJer() : SmearBase(){ name_ = "JER";}
        virtual int smear(Event*e);	

};

class SmearPu : virtual public SmearBase
{
    public:
        SmearPu() : SmearBase(){ name_ = "PU";}
        virtual int smear(Event*e);	
};

#endif
// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4 
