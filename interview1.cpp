#include <bits/stdc++.h>

using namespace std;

struct button {
    int low;
    int high;
    enum class state {
        off,
        pressed,
        on,
        released
    };
    state current_state = state::off;
    
    button(int low_, int high_): low(low_), high(high_) {}

    const char* current_state_str() {
        switch (current_state) {
            case state::off:
                return "off";
            case state::pressed:
                return "pressed";
            case state::on:
                return "on";
            case state::released:
                return "released";
        }
        return "";
    }
};/*
 * This function processes an ADC sample, modifying the states of the
 * buttons.
 */
/*
3
40 60       <- button 1
120 150     <- button 2
240 280     <- button 3


0
0
50  <- 1 = pressed
55  <- 1 = on
0   <- 1 = release
120 <- 2 = pressed , 1 = off
119
122
0
257
*/

void process_adc_input(
    /* in/out */ vector<button>& buttons,
    /* in */     int sample) {
    
    /* FILL IN THE CODE HERE */
    // off ->(hit) pressed ->(hit) -> on -> (no hit) Released -> (not hit) Off
    
    for (auto &button : buttons) {
        if (sample >= button.low && sample <= button.high) {
            cout << "Sample: " << sample << ", Hit Range( " << button.low << ", " << button.high << "), " << "cur state: " << button.current_state_str();
            if (button.current_state == button::state::off) button.current_state = button::state::pressed;
            else if (button.current_state == button::state::pressed) button.current_state = button::state::on;
            else if (button.current_state == button::state::on) button.current_state = button::state::on;
            else if (button.current_state == button::state::released) button.current_state = button::state::pressed;
            cout << " -> " << button.current_state_str() << endl;
        } else {
            cout << "Sample: " << sample << ", Not Hit Range, cur state: " << button.current_state_str();
            if (button.current_state == button::state::on) button.current_state = button::state::released;
            else if (button.current_state == button::state::pressed) button.current_state = button::state::released;
            else if (button.current_state == button::state::released) button.current_state = button::state::off;
            cout << " -> " << button.current_state_str() << endl;
        }
    }
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<button> buttons;

    int nButtons = 0;
    cin >> nButtons;
    
    for (int i = 0; i < nButtons; ++i) {
        int low = 0, high = 0;
        cin >> low >> high;
        buttons.emplace_back(low, high);
    }

    int nSamples = 0;
    cin >> nSamples;
    for (int i = 0; i < nSamples; ++i) {
        int sample = 0;
        cin >> sample;
        process_adc_input(buttons, sample);

        for (int j = 0; j < nButtons; ++j) {
            auto &btn = buttons[j];
            auto s = btn.current_state_str();
            fout << s;
            if (j + 1 != nButtons) {
                fout << " ";
            }
        }
        fout << endl;
    }

    return 0;
}
