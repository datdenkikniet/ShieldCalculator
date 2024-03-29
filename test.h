#ifndef SHIELDCALCULATOR_TEST_H
#define SHIELDCALCULATOR_TEST_H

#include "shieldbooster.h"
#include "shieldgenerator.h"

struct LoadOutStats {
    struct ShieldGenerator *generator;
    struct List *boosters;
    double hitPoints;
    double regenRate;
    double explosiveResistance;
    double kineticResistance;
    double thermalResistance;
};

struct TestConfig {
    double explosiveDPS;
    double kineticDPS;
    double thermalDPS;
    double absoluteDPS;
    double damageEffectiveness;
};

struct TestResult {
    struct LoadOutStats *loadOutStats;
    double survivalTime;
};

struct LoadOutStats *calculateLoadOutStats(struct ShieldGenerator *, struct List *);

struct TestResult *
calculateTestResult(struct ShieldGenerator *, struct List *, struct TestConfig);

struct TestResult *
findBestResultBooster(struct ShieldGenerator *, struct List *, struct TestConfig);

struct TestResult
*findBestResultGen(struct List *, struct List *, struct TestConfig);

struct TestResult
*findBestResult(struct List *, struct List *, struct TestConfig);

void printTestResult(struct TestResult *);

void freeResult(struct TestResult *);

void printTestConfig(struct TestConfig *);
#endif //SHIELDCALCULATOR_TEST_H
