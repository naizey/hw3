#ifndef GATE_H
#define GATE_H
#include <vector>
#include <queue>
#include <tuple>
#include "event.h"
#include "wire.h"

class Gate 
{
    public:
        Gate(int, Wire*);
        virtual ~Gate();
        virtual Event* update(uint64_t) =0;
        void wireInput(unsigned int,Wire*);
        
    protected:
      Wire* m_output; //a pointer to the wire connected to the gate's input
      std::vector<Wire*> m_inputs; //a vector of pointers to the wires connected to the gates inputs
			uint32_t m_delay;
			char m_current_state;
};

class And2Gate : public Gate
{
  public:
      And2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);  
};

class Or2Gate : public Gate
{
  public:
      Or2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);
};

//adding NotGate
class NotGate : public Gate
{
  public:
    NotGate(Wire*, Wire*);
    Event* update(uint64_t time);
};

#endif