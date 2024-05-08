/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 15,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "LineManager.h"

namespace seneca {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        std::ifstream stationFile(file);
        if (!stationFile.is_open()) {
            throw std::string("*** Cannot open the file ***");
        }

        std::string line;
        std::vector<std::string> workstations; // Store first part of each line (station)
        std::vector<std::string> nextWorkstations; // Store the second part of each line (next station)
        std::string lastWorkstation;

        while (std::getline(stationFile, line)) {
            std::istringstream iss(line);
            std::string workstation, nextWorkstation;
            if (line.find('|') != std::string::npos) {  //Check if the line contains '|', indicating two workstations
                std::getline(iss, workstation, '|');
                std::getline(iss, nextWorkstation);                       

               //Check if the first part of workstation exists in the list of stations
                auto findStation = std::find_if(stations.begin(), stations.end(),[&](const Workstation* station) { 
                    return station->getItemName() == workstation; });
                if (findStation != stations.end()) { //if it is found in the pool
                    //Check for duplicate stations
                    auto checkDuplicateStation = std::find_if(workstations.begin(), workstations.end(), [&](const std::string& station) {
                        return station == workstation;
                        });
                    if (checkDuplicateStation != workstations.end()) { //Throw exception if duplicate station is found
                        throw std::string("*** Duplicate Station ***");
                    }
                    else {
                        m_activeLine.push_back(*findStation);
                        workstations.push_back(workstation);
                    }             
                }
                else { //throw exception that station is not found in the pool
                    throw std::string("*** Station not found in pool ***");
                }

                //Check if the second part of workstation exists in the list of stations
                auto findNextStation = std::find_if(stations.begin(), stations.end(), [&](const Workstation* station) {
                    return station->getItemName() == nextWorkstation;
                    });

                if (findNextStation != stations.end()) {
                    auto checkDuplicateNextStation = std::find(nextWorkstations.begin(), nextWorkstations.end(), nextWorkstation);
                    //Check for duplicate stations
                    if (checkDuplicateNextStation != nextWorkstations.end()) {
                        throw std::string("*** Duplicate Next Work Station ***");
                    }
                    else {
                        m_activeLine.back()->setNextStation(*findNextStation);
                        nextWorkstations.push_back(nextWorkstation);
                    }
                }
                else {//throw exception that station is not found in the pool
                    throw std::string("*** Station not found in pool ***");
                }
            }
            else { //line does not contain"|",incicating last workstation
                if (!(lastWorkstation.empty())) {  //Check for duplicate stations
                    throw std::string("*** Duplicate last workstation ***");
                }
                std::getline(iss, lastWorkstation);
                //Check if the station exists in the list of stations
                auto lastStation = std::find_if(stations.begin(), stations.end(), [&](const Workstation* station) {
                    return station->getItemName() == lastWorkstation; });
                if (lastStation != stations.end()) {
                    m_activeLine.push_back(*lastStation);
                }
                else {
                    throw std::string("*** Station not found in pool ***");
                }            
            }
        }

        auto isWorkstationInNext = [&](const Workstation* workstation) {
            std::string workstationName = workstation->getItemName();
            // Check if the workstation name exists in the nextWorkstations vector
            // If it does not exist, return true, indicating that the workstation is not in the next list
            return std::find(nextWorkstations.begin(), nextWorkstations.end(), workstationName) == nextWorkstations.end();
            };  

        // Find the first station in the stations vector
        auto findFirstStation = std::find_if(stations.begin(), stations.end(), isWorkstationInNext);
        if (findFirstStation != stations.end()) {
            m_firstStation = *findFirstStation;
        }
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        std::vector<Workstation*> temp;
        Workstation* orderWorkstation = m_firstStation;
        while (orderWorkstation != nullptr) {
            temp.push_back(orderWorkstation);
            orderWorkstation = orderWorkstation->getNextStation();
        }
        m_activeLine = temp;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t iterationNumber = 0;
        ++iterationNumber;
        os << "Line Manager Iteration: " << iterationNumber << std::endl;

        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        for (auto station : m_activeLine) {
            station->fill(os);
        }

        for (auto station : m_activeLine) {
            station->attemptToMoveOrder();
        }
   
        return (g_completed.size()+g_incomplete.size()) == m_cntCustomerOrder; //check if all the customer orders have been filled
    }

    void LineManager::display(std::ostream& os) const {
        for (auto workstation : m_activeLine) {
            workstation->display(os);
        }
    }
}