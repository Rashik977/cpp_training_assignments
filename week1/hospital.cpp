#include <iostream>
#include <string>
#include <vector>

struct Symptoms
{
    int id;
    std::string type;
};

struct Medications
{
    int id;
    std::string name;
};

struct Diagnosis
{
    int id;
    std::string name;
};

struct MedicalRecord
{
    int id;
    std::vector<Diagnosis> diagnosis;
    std::vector<Medications> medications;
    std::vector<Symptoms> symptoms;
};

class Patient
{
public:
    Patient(int id, std::string name, std::string address, MedicalRecord mr)
    {
        this->id = id;
        this->name = name;
        this->address = address;
        this->mr = mr;
    }

private:
    int id;
    std::string name;
    std::string address;
    MedicalRecord mr;
};

class Hospital
{
public:
    Hospital() {

    };

    void addPatients(Patient patient)
    {
        patients.emplace_back(patient);
    }

private:
    std::vector<Patient> patients;
};

int main()
{
    MedicalRecord mr;
    mr.id = 1;
    mr.diagnosis.push_back({1, "Common Cold"});
    mr.medications.push_back({1, "Paracetamol"});
    mr.symptoms.push_back({1, "fever"});

    Patient p1(1, "birendra", "Kathmandu", mr);

    Hospital fishtail;

    fishtail.addPatients(p1);

    return 0;
}
