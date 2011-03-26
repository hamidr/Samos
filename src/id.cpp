#include "id.h"
#include "io.cpp"

enum cmdList {ADD = 0, SUB, MUL, DIV,
              LDA, STO, RWD, WWD,
              BRU, BMI, HLT, VAR};

ID::ID(QString *mem, QString *acc)
{
    cmd = -1;
    MBR = mem;
    ACC = acc;
    alu = new ALU(ACC);
    bus = new Bus(MBR, ACC);
}

void ID::setCode(QString *IR, int *pc)
{
    PC      = pc;
    Opcode  = IR->mid(0,3);
    Operand = IR->mid(6,4);
    this->state = this->deCode();
}

bool ID::deCode()
{
    if (Operand.isNull() || Opcode.isNull())
        return false;

    QString cmds[12] = {"ADD", "SUB", "MUL", "DIV",     // ALU  are 0 to 3
                        "LDA", "STO",                   // control bus
                        "RWD", "WWD",                   // state bus
                        "BRU", "BMI",                   // conditions
                        "HLT", "000"};                  // BYE signal

    for (int i=0; i<12; i++) // 0 to 11
    {
        if ( Opcode.compare(cmds[i], Qt::CaseSensitive) == 0 )
        {
            this->cmd = i;
            return true;
        }
    }

    qDebug() << "Line" <<*PC <<":" <<"Command Not found!";
    return false;
}

bool ID::run()
{
    if (! this->state)
        return false;

    switch (cmd)
    {

    case -1:
        qDebug() <<"No command here!";
        break;

    case ADD:
    case SUB:
    case MUL:
    case DIV:
        if (ACC->isEmpty()) {
            qDebug() << "ACC is empty!";
            return false;
        }
        alu->calc(cmd, MBR[Operand.toInt()].toInt());
        break;

    case LDA: // load to acc
        bus->load(Operand.toInt());
        break;

    case STO: // save from acc to mem
        bus->store(Operand.toInt());
        break;

    case RWD: // read from mem(i) and put it to acc
        IO::input(&MBR[Operand.toInt()]);
        break;

    case WWD: //write to mem from acc
        IO::output(&MBR[Operand.toInt()]); //**
        break;

    case BRU: // jump without conditions
        this->jumpAnyway(Operand.toInt());
        break;

    case BMI: // jump if minus
        this->jumpIfMinus(Operand.toInt());
        break;

    case HLT: // ~BYE
        return false;
        break;

    case VAR:
        break;
    }

    return true;
}

void ID::jumpAnyway(int n)
{
    n -= 1; // this is a semi-bug in loop of exec ;)
    *PC = n;
}

void ID::jumpIfMinus(int n)
{
    if ( ACC->toInt() < 0 )
    {
        n -= 1; // this is a semi-bug in loop of exec ;)
        *PC = n;
    }
}

ID::~ID()
{
    delete alu;
    delete bus;
}
