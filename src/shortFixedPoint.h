// value = valor a converter
// fp = número de casas depois da virgula a considerar (de 1 a 8 casas)

signed short doubleToShort(double value, int fp){
    if ((fp < 0)||(fp>8)) fp = 2;
    if ((value*10.0*fp < -32768.0)||(value*10.0*fp > 32768.0)){
        Serial.println("doubleToShort OVERFLOW");
        return 0;
    }

    signed short integ, fraction, converted;
    double temp;
    
    integ = int(value);
    temp = value - integ;
    temp = temp * 10.0 * fp;
    fraction = int(temp);
    converted = integ * 10*fp + fraction;
    
    return converted;
}   

double shortToDouble(signed short value, int fp){
    double converted;
    converted = value / (10.0*fp);
    return converted;
}
