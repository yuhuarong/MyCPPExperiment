#include "LinkedList.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int m = 335;
    //测试大数加法
    BigInteger integer0 = BigInteger::addMod(
            "12654678987687423974982379427349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349729347029374092374092309479023740927353",
            "34972934702937409237409230947349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349729347029374092374092309473497293470293740923740923094734972934702937409237409230947",
            m).trim();
    integer0.print();

    BigInteger integer1 = BigInteger::subMod(
            "126546789876874239749873274896138240192374927342093740923704972039750293750927305972375029375092375092375097230957203975029375029375023952379427349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349729347029374092374092309479023740927353",
            "349729347029374092374092309473497293470293740923740923094734972934702937409237409230947349235823987520973507230570293750927035823582052035283523572934702937409237409230947349729347029374092374092309473497293470293740923740923094734972934702937409237409230947",
            m).trim();
    integer1.print();

    BigInteger integer2 = BigInteger::multiMod(
            "12658172361628312368916391628936121928639123128463912739172093710927301921826398162938619286356718293761783172637819279812",
            "12836182631862391926391268381263619639162391872740970297490237623961928639182639812639612983619286339816293612039619023601230912",
            m).trim();
    integer2.print();

    BigInteger integer3 = BigInteger::divideMod(
            "8546541321465165154654145624134561235644126341426531425631284639127391720937109273019218263981629386192863567182937617831726378192798121265817236162831236891639162893612192863912312846391273917209371092730192182639816293861928635671829376178317263781927981212658172361628312368916391628936121928639123128463912739172093710927301921826398162938619286356718293761783172637819279812",
            "1283618263329849023844568796456418623919263912683812636196391623918623961928639182639812639612983619286339816293612039619023601230912",
            m).trim();
    integer3.print();

    time_t before=time(nullptr);
    cout << "before " << before <<endl;

    BigInteger integer4 = BigInteger::powMod(
            "67123712696396429614379878954564564564564564654654654879854132165797456146546415641561561126712345675464446747647475",
            "123113971297766657785785587587587987846584845262756276592738627382637826378625738527835278377723736812638139",
            m).trim();
    integer4.print();

    time_t after=time(nullptr);
    cout << "after " << after <<endl;

    return 0;
}