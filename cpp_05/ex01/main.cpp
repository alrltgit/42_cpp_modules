#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat br = Bureaucrat(2, "br1");
    Form good_form = Form("good_form", 3, 1);

    br.signForm(good_form);

    return 0;
}
