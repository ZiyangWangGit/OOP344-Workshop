/*************************************************************************************

*

* Student Name :Ziyang Wang

* Student ID  :154296222

* Course/Section: OOP345

* Date:Mar 05,2024

* I have done all the coding by myself and only copied the code that my professor

* provided to complete my workshops and assignments.

*

**************************************************************************************/
#include <iomanip>
#include "College.h"
#include "Employee.h"

namespace seneca {
	College::~College() {
		for (Person* person : m_persons) {
			delete person;
		}
	}

	College& College::operator +=(Person* thePerson) {
		m_persons.push_back(thePerson);
		return *this;
	}



	void College::display(std::ostream& out) const {
		static int testNum = 1;

		out << "------------------------------------------------------------------------------------------------------------------------" << std::endl 
			<< "|                                        Test #" << testNum
			<< " Persons in the college!                                               |" << std::endl
			<< "------------------------------------------------------------------------------------------------------------------------" << std::endl;

		std::vector<Person*>::iterator i;
		for (auto i = m_persons.begin(); i != m_persons.end(); ++i) {
			(*i)->display(out); 
		}
		out << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
		testNum++;
		
		out<< "|                                        Test #" << testNum
			<< " Persons in the college!                                               |" << std::endl
		   << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
			for (auto i = m_persons.begin(); i != m_persons.end(); ++i) {
				out << "| " << std::fixed << std::left << std::setw(10) << (*i)->status() << "| "
					<< std::setw(10) << (*i)->id() << "| "
					<< std::setw(20) << (*i)->name() << " | "
					<< std::setw(3) << (*i)->age() << " |" << std::endl;
			}
			out << "------------------------------------------------------------------------------------------------------------------------"<<std::endl;
			
	}

}