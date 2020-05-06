#ifndef BBAND_H
#define BBAND_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include "bank.h"

#include "TVector3.h"

class BBand : public hipo::bank {

	private:

    bool oldfile ;
		//for both BAND::hits (old and new structure)
		int id_order           ;
		int sector_order       ;
		int layer_order        ;
		int component_order    ;
		int x_order            ;
		int y_order            ;
		int z_order            ;
		int ux_order           ; //corresponds to ex in new BAND::hits
		int uy_order           ; //corresponds to ey in new BAND::hits
		int uz_order           ; //corresponds to ez in new BAND::hits
		int meantimeTdc_order  ; //corresponds to time in new BAND::hits
		int meantimeFadc_order ; //corresponds to timeFadc in new BAND::hits
		int difftimeTdc_order  ; //corresponds to difftime in new BAND::hits
		int difftimeFadc_order ; //corresponds to difftimeFadc in new BAND::hits
		//only new BAND::hits structure
		int energy_order       ;
		int indexLpmt_order    ;
		int indexLpmt_order    ;
		int status_order       ;
		//only old BAND::hits structure
		int adcLcorr_order     ;
		int adcRcorr_order     ;
		int tFadcLcorr_order   ;
		int tFadcRcorr_order   ;
		int tTdcLcorr_order    ;
		int tTdcRcorr_order    ;


	public:

		BBand(){};

		BBand(hipo::schema __schema,int __old);
		BBand(hipo::schema __schema);

		~BBand();

		bool  isOldfile       () 					{ return oldfile;}
		int   getId           (int index) { return getInt   (id_order           ,index);}
		int   getSector       (int index) { return getInt   (sector_order       ,index);}
		int   getLayer        (int index) { return getInt   (layer_order        ,index);}
		int   getComponent    (int index) { return getInt   (component_order    ,index);}
		float getMeantimeTdc  (int index) { return getFloat (meantimeTdc_order  ,index);}
		float getMeantimeFadc (int index) { return getFloat (meantimeFadc_order ,index);}
		float getDifftimeTdc  (int index) { return getFloat (difftimeTdc_order  ,index);}
		float getDifftimeFadc (int index) { return getFloat (difftimeFadc_order ,index);}
		float getAdcLcorr     (int index) { return getFloat (adcLcorr_order     ,index);}
		float getAdcRcorr     (int index) { return getFloat (adcRcorr_order     ,index);}
		float getTfadcLcorr   (int index) { return getFloat (tFadcLcorr_order   ,index);}
		float getTfadcRcorr   (int index) { return getFloat (tFadcRcorr_order   ,index);}
		float getTtdcLcorr    (int index) { return getFloat (tTdcLcorr_order    ,index);}
		float getTtdcRcorr    (int index) { return getFloat (tTdcRcorr_order    ,index);}
		float getX            (int index) { return getFloat (x_order            ,index);}
		float getY            (int index) { return getFloat (y_order            ,index);}
		float getZ            (int index) { return getFloat (z_order            ,index);}
		float getUx           (int index) { return getFloat (ux_order           ,index);}
		float getUy           (int index) { return getFloat (uy_order           ,index);}
		float getUz           (int index) { return getFloat (uz_order           ,index);}
		//next functions are for BAND::hits new structure. some of them are mapped to the same class members than previous get-functions
		float getEx           (int index) { return getFloat (ux_order           ,index);}
		float getEy           (int index) { return getFloat (uy_order           ,index);}
		float getEz           (int index) { return getFloat (uz_order           ,index);}
		float getTime         (int index) { return getFloat (meantimeTdc_order  ,index);}
		float getTimeFadc     (int index) { return getFloat (meantimeFadc_order ,index);}
		float getEnergy       (int index) { return getFloat (energy_order       ,index);}
		int   getLpmtindex    (int index) { return getInt   (indexLpmt_order    ,index);}
		int   getRpmtindex    (int index) { return getInt   (indexRpmt_order    ,index);}
		int   getStatus       (int index) { return getInt   (status_order       ,index);}


		int   getBarKey(int index);
};

#endif
