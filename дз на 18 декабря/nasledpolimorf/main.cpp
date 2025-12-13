#include <iostream>
#include <cmath>
#include <iomanip>

class SignalGenerator {
protected:
    double amplitude;
    double frequency;
    double phase;

public:
    SignalGenerator(double amp = 1.0, double freq = 1.0, double ph = 0.0)
        : amplitude(amp), frequency(freq), phase(ph) {}

    virtual ~SignalGenerator() {}

    virtual double getAmplitude() const { return amplitude; }
    virtual void setAmplitude(double amp) { amplitude = amp; }

    virtual double getFrequency() const { return frequency; }
    virtual void setFrequency(double freq) { frequency = freq; }

    virtual double getPhase() const { return phase; }
    virtual void setPhase(double ph) { phase = ph; }

    virtual double calculate(double time) const = 0;

    virtual void printInfo() const {
        std::cout << "amplitude: " << amplitude << ", frequency: " << frequency
                  << " Hz, phase: " << phase << " rad" << std::endl;
    }

    virtual void generateAndPrint(int count, double timeStep) const {
        for (int i = 0; i < count; ++i) {
            double time = i * timeStep;
            std::cout << std::fixed << std::setprecision(4)
                      << "t=" << time << ", x(t)=" << calculate(time) << std::endl;
        }
    }
};

class SineGenerator : public SignalGenerator {
public:
    SineGenerator(double amp = 1.0, double freq = 1.0, double ph = 0.0)
        : SignalGenerator(amp, freq, ph) {}

    double calculate(double time) const override {
        return amplitude * std::sin(2 * M_PI * frequency * time + phase);
    }

    void printInfo() const override {
        std::cout << "sinusoidal signal: ";
        SignalGenerator::printInfo();
    }
};

class SquareGenerator : public SignalGenerator {
public:
    SquareGenerator(double amp = 1.0, double freq = 1.0, double ph = 0.0)
        : SignalGenerator(amp, freq, ph) {}

    double calculate(double time) const override {
        return amplitude * (std::sin(2 * M_PI * frequency * time + phase) >= 0 ? 1 : -1);
    }

    void printInfo() const override {
        std::cout << "rectangular signal: ";
        SignalGenerator::printInfo();
    }
};

class TriangleGenerator : public SignalGenerator {
public:
    TriangleGenerator(double amp = 1.0, double freq = 1.0, double ph = 0.0)
        : SignalGenerator(amp, freq, ph) {}

    double calculate(double time) const override {
        return (2 * amplitude / M_PI) * std::asin(std::sin(2 * M_PI * frequency * time + phase));
    }

    void printInfo() const override {
        std::cout << "triangular signal: ";
        SignalGenerator::printInfo();
    }
};

int main() {
    const int GENERATOR_COUNT = 3;
    SignalGenerator* generators[GENERATOR_COUNT];

    generators[0] = new SineGenerator(1.0, 2.0, 0.0);
    generators[1] = new SquareGenerator(1.0, 2.0, 0.0);
    generators[2] = new TriangleGenerator(1.0, 2.0, 0.0);

    for (int i = 0; i < GENERATOR_COUNT; ++i) {
        generators[i]->printInfo();
        generators[i]->generateAndPrint(100, 0.01);
        std::cout << "------------------------" << std::endl;
    }

    SignalGenerator* signal = new SineGenerator(0.5, 1.0, 0.0);
    std::cout << "value in t=0.5: " << signal->calculate(0.5) << std::endl;

    delete signal;
    signal = new SquareGenerator(0.5, 1.0, 0.0);
    std::cout << "value in t=0.5: " << signal->calculate(0.5) << std::endl;

    for (int i = 0; i < GENERATOR_COUNT; ++i) {
        delete generators[i];
    }
    delete signal;

    return 0;
}
