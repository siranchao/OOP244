// Final Project Milestone 4
// Student Name: Siran Cao
// ID: 159235209
// Revision History
// -----------------------------------------------------------
// Version               Date                 Reason
// 1.0         	       11/26/2021             ms-4 submission
/////////////////////////////////////////////////////////////////

#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
namespace sdds {

	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& io)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();

	};
	std::ostream& operator<<(std::ostream& os, const Streamable& src);
	std::istream& operator>>(std::istream& is, Streamable& src);

}

#endif // !SDDS_STREAMABLE_H__
