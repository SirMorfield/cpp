#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("no name"), grade(grade_min) {
}

void Bureaucrat::setGrade(long grade) {
	if (grade < grade_min)
		throw GradeTooLowException();
	else if (grade > grade_max)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const std::string& name, long grade) : name(name) {
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& cp) {
	*this = cp;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cp) {
	this->grade = cp.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return name;
}

long Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	setGrade(grade - 1);
}

void Bureaucrat::decrementGrade() {
	setGrade(grade + 1);
}

void Bureaucrat::signForm(const Form& f) const {
	if (grade > f.getGradeSign())
		std::cout << "Bureaucrat " << name << " cannot sign form " << f.getName() << " because grade is too low" << std::endl;
	else
		std::cout << "Bureaucrat " << name << " signs form " << f.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& target) {
	out << "name: " << target.getName() << ", grade: " << target.getGrade();
	return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade too low";
}