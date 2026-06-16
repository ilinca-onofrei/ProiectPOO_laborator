#ifndef REDUCERE_STRATEGY_H
#define REDUCERE_STRATEGY_H

class ReducereStrategy {
public:
    virtual double aplica(double pret) = 0;

    virtual ~ReducereStrategy() = default;
};

class Reducere10 : public ReducereStrategy {
public:
    double aplica(double pret) override {
        return pret * 0.9;
    }
};

class Reducere20 : public ReducereStrategy {
public:
    double aplica(double pret) override {
        return pret * 0.8;
    }
};

#endif
