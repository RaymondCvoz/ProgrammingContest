#include <iostream>
#include <string>

int main()
{
    std::string s, a_x_axis, a_y_axis, a_z_axis, b_x_axis, b_y_axis, b_z_axis;
    while (std::cin >> s)
    {
        a_x_axis = s[0] + s[5];
        a_y_axis = s[1] + s[4];
        a_z_axis = s[2] + s[3];
        b_x_axis = s[6] + s[11];
        b_y_axis = s[7] + s[10];
        b_z_axis = s[8] + s[9];
        if ((a_x_axis == b_x_axis || a_x_axis == b_y_axis || a_x_axis == b_z_axis) && (a_y_axis == b_x_axis || a_y_axis == b_y_axis || a_y_axis == b_z_axis) && (a_z_axis == b_x_axis || a_z_axis == b_y_axis || a_z_axis == b_z_axis))
            if ((b_x_axis == a_x_axis || b_x_axis == a_y_axis || b_x_axis == a_z_axis) && (b_y_axis == a_x_axis || b_y_axis == a_y_axis || b_y_axis == a_z_axis) && (b_z_axis == a_x_axis || b_z_axis == a_y_axis || b_z_axis == a_z_axis))
                std::cout << "TRUE" << std::endl;
            else
                std::cout << "FALSE" << std::endl;
        else
            std::cout << "FALSE" << std::endl;
    }
    return 0;
}