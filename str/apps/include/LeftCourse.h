/**
 * @file LeftCourse.h
 * @brief Lコースを走らせるときに呼び出されるクラス
 * @author Futa HIRAKOBA
 */

#ifndef __LEFT_COURSE__
#define __LEFT_COURSE__

#define IS_SHORT_CUT 0

#include "Walker.h"
#include "ColorSensor.h"
#include "LeftNormalCourse.h"
#include "SelfLocalization.h"

using namespace ev3api;

/**
* Lコースを走らせるときに呼び出されるクラス
*/
class LeftCourse {
public:
	/** コンストラクタ。センサ類の初期化を行う */
	LeftCourse();

    /**
     * このクラスのインスタンスを保持しているインスタンスまたはメンバ関数が、
     * UserInterfaceクラスのgetFirstCodeメンバ関数から
     * 取得した初期位置コードを入力する。
     * @param 初期位置コード 0から99999まで
     */
    void setFirstCode( int32_t );

	/** 各エリアの処理を呼び出す */
	void run();
	/** NormalCourseエリアの処理 */
    void runNormalCourse();
    /**
     * ブロック並べを行う。
     * PuzzleFieldクラスに依存する。
     */
    void runBlockRange();

    /**
     * 縦列駐車を行う。
     * Parkingクラスに依存する。
     */
    void runParallelParking();

private:
	Walker walker;
    ColorSensor colorSensor;
    /** 自己位置推定 インスタンス 初期化*/
	SelfLocalization sl;
    /**
     * UserInterfaceの初期位置コードを記録する。
     * ブロック並べに用いる。
     */
    int32_t firstCode;
};

#endif
