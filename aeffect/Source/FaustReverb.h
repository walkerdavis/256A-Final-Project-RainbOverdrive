/* ------------------------------------------------------------
Code generated with Faust 2.0.a46 (http://faust.grame.fr)
------------------------------------------------------------ */

#ifndef  __FaustReverb_H__
#define  __FaustReverb_H__
// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

//----------------------------------------------------------------
//  Signal processor definition
//----------------------------------------------------------------

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;
        virtual void buildUserInterface(UI* ui_interface) = 0;
        virtual int getSampleRate() = 0;
        virtual void init(int samplingRate) = 0;
        virtual void instanceInit(int samplingRate) = 0;
        virtual void instanceClear() = 0;
        virtual dsp* clone() = 0;
        virtual void metadata(Meta* m) = 0;
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

//----------------------------------------------------------------
// DSP factory class
//----------------------------------------------------------------

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual dsp* createDSPInstance() = 0;
    
};

//----------------------------------------------------------------
// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
//----------------------------------------------------------------

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  

#include <math.h>



#ifndef FAUSTCLASS 
#define FAUSTCLASS FaustReverb
#endif

class FaustReverb : public dsp {
	
  private:
	
	float fVec9[16384];
	float fVec14[16384];
	float fVec16[16384];
	float fVec0[8192];
	float fVec1[8192];
	float fVec3[8192];
	float fVec5[8192];
	float fVec7[8192];
	float fVec10[8192];
	float fVec12[8192];
	float fVec4[2048];
	float fVec6[2048];
	float fVec11[2048];
	float fVec13[2048];
	float fVec15[2048];
	float fVec2[1024];
	float fVec8[1024];
	float fVec17[1024];
	float fRec4[3];
	float fRec5[3];
	float fRec6[3];
	float fRec7[3];
	float fRec8[3];
	float fRec9[3];
	float fRec10[3];
	float fRec11[3];
	float fRec3[3];
	float fRec2[3];
	float fRec45[3];
	float fRec44[3];
	float fRec0[2];
	float fRec1[2];
	float fRec15[2];
	float fRec14[2];
	float fRec12[2];
	float fRec19[2];
	float fRec18[2];
	float fRec16[2];
	float fRec23[2];
	float fRec22[2];
	float fRec20[2];
	float fRec27[2];
	float fRec26[2];
	float fRec24[2];
	float fRec31[2];
	float fRec30[2];
	float fRec28[2];
	float fRec35[2];
	float fRec34[2];
	float fRec32[2];
	float fRec39[2];
	float fRec38[2];
	float fRec36[2];
	float fRec43[2];
	float fRec42[2];
	float fRec40[2];
	FAUSTFLOAT fVslider0;
	int IOTA;
	FAUSTFLOAT fVslider1;
	FAUSTFLOAT fVslider2;
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fVslider4;
	FAUSTFLOAT fVslider5;
	float fConst2;
	FAUSTFLOAT fVslider6;
	float fConst3;
	FAUSTFLOAT fVslider7;
	float fConst4;
	float fConst5;
	FAUSTFLOAT fVslider8;
	FAUSTFLOAT fVslider9;
	float fConst6;
	FAUSTFLOAT fVslider10;
	float fConst7;
	int iConst8;
	int iConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	int iConst13;
	int iConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	int iConst18;
	int iConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	int iConst23;
	int iConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	int iConst28;
	int iConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	int iConst33;
	int iConst34;
	float fConst35;
	float fConst36;
	float fConst37;
	int iConst38;
	int iConst39;
	float fConst40;
	float fConst41;
	float fConst42;
	int iConst43;
	int iConst44;
	
  public:
	
    float faustpower2_f(float value) {
        return (value * value);
        
    }
    
	void metadata(Meta* m) { 
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/license", "STK-4.3");
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/version", "1.33");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("filter.lib/version", "1.29");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/version", "1.0");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/version", "1.0");
	}

	virtual int getNumInputs() {
		return 2;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fVslider0 = FAUSTFLOAT(-20.0f);
		fVslider1 = FAUSTFLOAT(0.0f);
		fVslider2 = FAUSTFLOAT(0.0f);
		fConst0 = min(192000.0f, max(1.0f, float(fSamplingFreq)));
		fConst1 = (6.28318548f / fConst0);
		fVslider3 = FAUSTFLOAT(1500.0f);
		fVslider4 = FAUSTFLOAT(0.0f);
		fVslider5 = FAUSTFLOAT(315.0f);
		fConst2 = (0.00100000005f * fConst0);
		fVslider6 = FAUSTFLOAT(60.0f);
		fConst3 = (6.28318548f / fConst0);
		fVslider7 = FAUSTFLOAT(6000.0f);
		fConst4 = floorf((0.5f + (0.153128996f * fConst0)));
		fConst5 = ((0.0f - (6.90775537f * fConst4)) / fConst0);
		fVslider8 = FAUSTFLOAT(2.0f);
		fVslider9 = FAUSTFLOAT(3.0f);
		fConst6 = (3.14159274f / fConst0);
		fVslider10 = FAUSTFLOAT(200.0f);
		fConst7 = floorf((0.5f + (0.0203460008f * fConst0)));
		iConst8 = (int((fConst4 - fConst7)) & 8191);
		iConst9 = (int((fConst7 - 1.0f)) & 1023);
		fConst10 = floorf((0.5f + (0.174713001f * fConst0)));
		fConst11 = ((0.0f - (6.90775537f * fConst10)) / fConst0);
		fConst12 = floorf((0.5f + (0.0229039993f * fConst0)));
		iConst13 = (int((fConst10 - fConst12)) & 8191);
		iConst14 = (int((fConst12 - 1.0f)) & 2047);
		fConst15 = floorf((0.5f + (0.127837002f * fConst0)));
		fConst16 = ((0.0f - (6.90775537f * fConst15)) / fConst0);
		fConst17 = floorf((0.5f + (0.0316039994f * fConst0)));
		iConst18 = (int((fConst15 - fConst17)) & 8191);
		iConst19 = (int((fConst17 - 1.0f)) & 2047);
		fConst20 = floorf((0.5f + (0.125f * fConst0)));
		fConst21 = ((0.0f - (6.90775537f * fConst20)) / fConst0);
		fConst22 = floorf((0.5f + (0.0134579996f * fConst0)));
		iConst23 = (int((fConst20 - fConst22)) & 8191);
		iConst24 = (int((fConst22 - 1.0f)) & 1023);
		fConst25 = floorf((0.5f + (0.210389003f * fConst0)));
		fConst26 = ((0.0f - (6.90775537f * fConst25)) / fConst0);
		fConst27 = floorf((0.5f + (0.0244210009f * fConst0)));
		iConst28 = (int((fConst25 - fConst27)) & 16383);
		iConst29 = (int((fConst27 - 1.0f)) & 2047);
		fConst30 = floorf((0.5f + (0.192303002f * fConst0)));
		fConst31 = ((0.0f - (6.90775537f * fConst30)) / fConst0);
		fConst32 = floorf((0.5f + (0.0292910002f * fConst0)));
		iConst33 = (int((fConst30 - fConst32)) & 8191);
		iConst34 = (int((fConst32 - 1.0f)) & 2047);
		fConst35 = floorf((0.5f + (0.256891012f * fConst0)));
		fConst36 = ((0.0f - (6.90775537f * fConst35)) / fConst0);
		fConst37 = floorf((0.5f + (0.0273330007f * fConst0)));
		iConst38 = (int((fConst35 - fConst37)) & 16383);
		iConst39 = (int((fConst37 - 1.0f)) & 2047);
		fConst40 = floorf((0.5f + (0.219990999f * fConst0)));
		fConst41 = ((0.0f - (6.90775537f * fConst40)) / fConst0);
		fConst42 = floorf((0.5f + (0.0191229992f * fConst0)));
		iConst43 = (int((fConst40 - fConst42)) & 16383);
		iConst44 = (int((fConst42 - 1.0f)) & 1023);
		instanceClear();
	}
	
	virtual void instanceClear() {
		for (int i0 = 0; (i0 < 2); i0 = (i0 + 1)) {
			fRec0[i0] = 0.0f;
			
		}
		IOTA = 0;
		for (int i1 = 0; (i1 < 8192); i1 = (i1 + 1)) {
			fVec0[i1] = 0.0f;
			
		}
		for (int i2 = 0; (i2 < 2); i2 = (i2 + 1)) {
			fRec1[i2] = 0.0f;
			
		}
		for (int i3 = 0; (i3 < 2); i3 = (i3 + 1)) {
			fRec15[i3] = 0.0f;
			
		}
		for (int i4 = 0; (i4 < 2); i4 = (i4 + 1)) {
			fRec14[i4] = 0.0f;
			
		}
		for (int i5 = 0; (i5 < 8192); i5 = (i5 + 1)) {
			fVec1[i5] = 0.0f;
			
		}
		for (int i6 = 0; (i6 < 1024); i6 = (i6 + 1)) {
			fVec2[i6] = 0.0f;
			
		}
		for (int i7 = 0; (i7 < 2); i7 = (i7 + 1)) {
			fRec12[i7] = 0.0f;
			
		}
		for (int i8 = 0; (i8 < 2); i8 = (i8 + 1)) {
			fRec19[i8] = 0.0f;
			
		}
		for (int i9 = 0; (i9 < 2); i9 = (i9 + 1)) {
			fRec18[i9] = 0.0f;
			
		}
		for (int i10 = 0; (i10 < 8192); i10 = (i10 + 1)) {
			fVec3[i10] = 0.0f;
			
		}
		for (int i11 = 0; (i11 < 2048); i11 = (i11 + 1)) {
			fVec4[i11] = 0.0f;
			
		}
		for (int i12 = 0; (i12 < 2); i12 = (i12 + 1)) {
			fRec16[i12] = 0.0f;
			
		}
		for (int i13 = 0; (i13 < 2); i13 = (i13 + 1)) {
			fRec23[i13] = 0.0f;
			
		}
		for (int i14 = 0; (i14 < 2); i14 = (i14 + 1)) {
			fRec22[i14] = 0.0f;
			
		}
		for (int i15 = 0; (i15 < 8192); i15 = (i15 + 1)) {
			fVec5[i15] = 0.0f;
			
		}
		for (int i16 = 0; (i16 < 2048); i16 = (i16 + 1)) {
			fVec6[i16] = 0.0f;
			
		}
		for (int i17 = 0; (i17 < 2); i17 = (i17 + 1)) {
			fRec20[i17] = 0.0f;
			
		}
		for (int i18 = 0; (i18 < 2); i18 = (i18 + 1)) {
			fRec27[i18] = 0.0f;
			
		}
		for (int i19 = 0; (i19 < 2); i19 = (i19 + 1)) {
			fRec26[i19] = 0.0f;
			
		}
		for (int i20 = 0; (i20 < 8192); i20 = (i20 + 1)) {
			fVec7[i20] = 0.0f;
			
		}
		for (int i21 = 0; (i21 < 1024); i21 = (i21 + 1)) {
			fVec8[i21] = 0.0f;
			
		}
		for (int i22 = 0; (i22 < 2); i22 = (i22 + 1)) {
			fRec24[i22] = 0.0f;
			
		}
		for (int i23 = 0; (i23 < 2); i23 = (i23 + 1)) {
			fRec31[i23] = 0.0f;
			
		}
		for (int i24 = 0; (i24 < 2); i24 = (i24 + 1)) {
			fRec30[i24] = 0.0f;
			
		}
		for (int i25 = 0; (i25 < 16384); i25 = (i25 + 1)) {
			fVec9[i25] = 0.0f;
			
		}
		for (int i26 = 0; (i26 < 8192); i26 = (i26 + 1)) {
			fVec10[i26] = 0.0f;
			
		}
		for (int i27 = 0; (i27 < 2048); i27 = (i27 + 1)) {
			fVec11[i27] = 0.0f;
			
		}
		for (int i28 = 0; (i28 < 2); i28 = (i28 + 1)) {
			fRec28[i28] = 0.0f;
			
		}
		for (int i29 = 0; (i29 < 2); i29 = (i29 + 1)) {
			fRec35[i29] = 0.0f;
			
		}
		for (int i30 = 0; (i30 < 2); i30 = (i30 + 1)) {
			fRec34[i30] = 0.0f;
			
		}
		for (int i31 = 0; (i31 < 8192); i31 = (i31 + 1)) {
			fVec12[i31] = 0.0f;
			
		}
		for (int i32 = 0; (i32 < 2048); i32 = (i32 + 1)) {
			fVec13[i32] = 0.0f;
			
		}
		for (int i33 = 0; (i33 < 2); i33 = (i33 + 1)) {
			fRec32[i33] = 0.0f;
			
		}
		for (int i34 = 0; (i34 < 2); i34 = (i34 + 1)) {
			fRec39[i34] = 0.0f;
			
		}
		for (int i35 = 0; (i35 < 2); i35 = (i35 + 1)) {
			fRec38[i35] = 0.0f;
			
		}
		for (int i36 = 0; (i36 < 16384); i36 = (i36 + 1)) {
			fVec14[i36] = 0.0f;
			
		}
		for (int i37 = 0; (i37 < 2048); i37 = (i37 + 1)) {
			fVec15[i37] = 0.0f;
			
		}
		for (int i38 = 0; (i38 < 2); i38 = (i38 + 1)) {
			fRec36[i38] = 0.0f;
			
		}
		for (int i39 = 0; (i39 < 2); i39 = (i39 + 1)) {
			fRec43[i39] = 0.0f;
			
		}
		for (int i40 = 0; (i40 < 2); i40 = (i40 + 1)) {
			fRec42[i40] = 0.0f;
			
		}
		for (int i41 = 0; (i41 < 16384); i41 = (i41 + 1)) {
			fVec16[i41] = 0.0f;
			
		}
		for (int i42 = 0; (i42 < 1024); i42 = (i42 + 1)) {
			fVec17[i42] = 0.0f;
			
		}
		for (int i43 = 0; (i43 < 2); i43 = (i43 + 1)) {
			fRec40[i43] = 0.0f;
			
		}
		for (int i44 = 0; (i44 < 3); i44 = (i44 + 1)) {
			fRec4[i44] = 0.0f;
			
		}
		for (int i45 = 0; (i45 < 3); i45 = (i45 + 1)) {
			fRec5[i45] = 0.0f;
			
		}
		for (int i46 = 0; (i46 < 3); i46 = (i46 + 1)) {
			fRec6[i46] = 0.0f;
			
		}
		for (int i47 = 0; (i47 < 3); i47 = (i47 + 1)) {
			fRec7[i47] = 0.0f;
			
		}
		for (int i48 = 0; (i48 < 3); i48 = (i48 + 1)) {
			fRec8[i48] = 0.0f;
			
		}
		for (int i49 = 0; (i49 < 3); i49 = (i49 + 1)) {
			fRec9[i49] = 0.0f;
			
		}
		for (int i50 = 0; (i50 < 3); i50 = (i50 + 1)) {
			fRec10[i50] = 0.0f;
			
		}
		for (int i51 = 0; (i51 < 3); i51 = (i51 + 1)) {
			fRec11[i51] = 0.0f;
			
		}
		for (int i52 = 0; (i52 < 3); i52 = (i52 + 1)) {
			fRec3[i52] = 0.0f;
			
		}
		for (int i53 = 0; (i53 < 3); i53 = (i53 + 1)) {
			fRec2[i53] = 0.0f;
			
		}
		for (int i54 = 0; (i54 < 3); i54 = (i54 + 1)) {
			fRec45[i54] = 0.0f;
			
		}
		for (int i55 = 0; (i55 < 3); i55 = (i55 + 1)) {
			fRec44[i55] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	virtual FaustReverb* clone() {
		return new FaustReverb();
	}
	
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "0", "");
		ui_interface->declare(0, "tooltip", "~ ZITA REV1 FEEDBACK DELAY NETWORK (FDN) & SCHROEDER ALLPASS-COMB REVERBERATOR (8x8). See Faust's effect.lib for documentation and references");
		ui_interface->openHorizontalBox("Zita_Rev1");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Input");
		ui_interface->declare(&fVslider6, "1", "");
		ui_interface->declare(&fVslider6, "style", "knob");
		ui_interface->declare(&fVslider6, "tooltip", "Delay in ms before reverberation begins");
		ui_interface->declare(&fVslider6, "unit", "ms");
		ui_interface->addVerticalSlider("In Delay", &fVslider6, 60.0f, 20.0f, 100.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Decay Times in Bands (see tooltips)");
		ui_interface->declare(&fVslider10, "1", "");
		ui_interface->declare(&fVslider10, "scale", "log");
		ui_interface->declare(&fVslider10, "style", "knob");
		ui_interface->declare(&fVslider10, "tooltip", "Crossover frequency (Hz) separating low and middle frequencies");
		ui_interface->declare(&fVslider10, "unit", "Hz");
		ui_interface->addVerticalSlider("LF X", &fVslider10, 200.0f, 50.0f, 1000.0f, 1.0f);
		ui_interface->declare(&fVslider9, "2", "");
		ui_interface->declare(&fVslider9, "scale", "log");
		ui_interface->declare(&fVslider9, "style", "knob");
		ui_interface->declare(&fVslider9, "tooltip", "T60 = time (in seconds) to decay 60dB in low-frequency band");
		ui_interface->declare(&fVslider9, "unit", "s");
		ui_interface->addVerticalSlider("Low RT60", &fVslider9, 3.0f, 1.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fVslider8, "3", "");
		ui_interface->declare(&fVslider8, "scale", "log");
		ui_interface->declare(&fVslider8, "style", "knob");
		ui_interface->declare(&fVslider8, "tooltip", "T60 = time (in seconds) to decay 60dB in middle band");
		ui_interface->declare(&fVslider8, "unit", "s");
		ui_interface->addVerticalSlider("Mid RT60", &fVslider8, 2.0f, 1.0f, 8.0f, 0.100000001f);
		ui_interface->declare(&fVslider7, "4", "");
		ui_interface->declare(&fVslider7, "scale", "log");
		ui_interface->declare(&fVslider7, "style", "knob");
		ui_interface->declare(&fVslider7, "tooltip", "Frequency (Hz) at which the high-frequency T60 is half the middle-band's T60");
		ui_interface->declare(&fVslider7, "unit", "Hz");
		ui_interface->addVerticalSlider("HF Damping", &fVslider7, 6000.0f, 1500.0f, 23520.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 1");
		ui_interface->declare(&fVslider5, "1", "");
		ui_interface->declare(&fVslider5, "scale", "log");
		ui_interface->declare(&fVslider5, "style", "knob");
		ui_interface->declare(&fVslider5, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider5, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq1 Freq", &fVslider5, 315.0f, 40.0f, 2500.0f, 1.0f);
		ui_interface->declare(&fVslider4, "2", "");
		ui_interface->declare(&fVslider4, "style", "knob");
		ui_interface->declare(&fVslider4, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 1");
		ui_interface->declare(&fVslider4, "unit", "dB");
		ui_interface->addVerticalSlider("Eq1 Level", &fVslider4, 0.0f, -15.0f, 15.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "4", "");
		ui_interface->openHorizontalBox("RM Peaking Equalizer 2");
		ui_interface->declare(&fVslider3, "1", "");
		ui_interface->declare(&fVslider3, "scale", "log");
		ui_interface->declare(&fVslider3, "style", "knob");
		ui_interface->declare(&fVslider3, "tooltip", "Center-frequency of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider3, "unit", "Hz");
		ui_interface->addVerticalSlider("Eq2 Freq", &fVslider3, 1500.0f, 160.0f, 10000.0f, 1.0f);
		ui_interface->declare(&fVslider2, "2", "");
		ui_interface->declare(&fVslider2, "style", "knob");
		ui_interface->declare(&fVslider2, "tooltip", "Peak level in dB of second-order Regalia-Mitra peaking equalizer section 2");
		ui_interface->declare(&fVslider2, "unit", "dB");
		ui_interface->addVerticalSlider("Eq2 Level", &fVslider2, 0.0f, -15.0f, 15.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->declare(0, "5", "");
		ui_interface->openHorizontalBox("Output");
		ui_interface->declare(&fVslider1, "1", "");
		ui_interface->declare(&fVslider1, "style", "knob");
		ui_interface->declare(&fVslider1, "tooltip", "-1 = dry, 1 = wet");
		ui_interface->addVerticalSlider("Dry/Wet Mix", &fVslider1, 0.0f, -1.0f, 1.0f, 0.00999999978f);
		ui_interface->declare(&fVslider0, "2", "");
		ui_interface->declare(&fVslider0, "style", "knob");
		ui_interface->declare(&fVslider0, "tooltip", "Output scale factor");
		ui_interface->declare(&fVslider0, "unit", "dB");
		ui_interface->addVerticalSlider("Level", &fVslider0, -20.0f, -70.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * powf(10.0f, (0.0500000007f * float(fVslider0))));
		float fSlow1 = (0.00100000005f * float(fVslider1));
		float fSlow2 = powf(10.0f, (0.0500000007f * float(fVslider2)));
		float fSlow3 = float(fVslider3);
		float fSlow4 = (fConst1 * (fSlow3 / sqrtf(max(0.0f, fSlow2))));
		float fSlow5 = ((1.0f - fSlow4) / (1.0f + fSlow4));
		float fSlow6 = ((1.0f + fSlow5) * (0.0f - cosf((fConst1 * fSlow3))));
		float fSlow7 = powf(10.0f, (0.0500000007f * float(fVslider4)));
		float fSlow8 = float(fVslider5);
		float fSlow9 = (fConst1 * (fSlow8 / sqrtf(max(0.0f, fSlow7))));
		float fSlow10 = ((1.0f - fSlow9) / (1.0f + fSlow9));
		float fSlow11 = ((1.0f + fSlow10) * (0.0f - cosf((fConst1 * fSlow8))));
		int iSlow12 = (int((fConst2 * float(fVslider6))) & 8191);
		float fSlow13 = cosf((fConst3 * float(fVslider7)));
		float fSlow14 = float(fVslider8);
		float fSlow15 = expf((fConst5 / fSlow14));
		float fSlow16 = faustpower2_f(fSlow15);
		float fSlow17 = (1.0f - (fSlow13 * fSlow16));
		float fSlow18 = (1.0f - fSlow16);
		float fSlow19 = (fSlow17 / fSlow18);
		float fSlow20 = sqrtf(max(0.0f, ((faustpower2_f(fSlow17) / faustpower2_f(fSlow18)) - 1.0f)));
		float fSlow21 = (fSlow19 - fSlow20);
		float fSlow22 = (fSlow15 * ((1.0f + fSlow20) - fSlow19));
		float fSlow23 = float(fVslider9);
		float fSlow24 = ((expf((fConst5 / fSlow23)) / fSlow15) - 1.0f);
		float fSlow25 = (1.0f / tanf((fConst6 * float(fVslider10))));
		float fSlow26 = (1.0f + fSlow25);
		float fSlow27 = (1.0f / fSlow26);
		float fSlow28 = (0.0f - ((1.0f - fSlow25) / fSlow26));
		float fSlow29 = expf((fConst11 / fSlow14));
		float fSlow30 = faustpower2_f(fSlow29);
		float fSlow31 = (1.0f - (fSlow30 * fSlow13));
		float fSlow32 = (1.0f - fSlow30);
		float fSlow33 = (fSlow31 / fSlow32);
		float fSlow34 = sqrtf(max(0.0f, ((faustpower2_f(fSlow31) / faustpower2_f(fSlow32)) - 1.0f)));
		float fSlow35 = (fSlow33 - fSlow34);
		float fSlow36 = (fSlow29 * ((1.0f + fSlow34) - fSlow33));
		float fSlow37 = ((expf((fConst11 / fSlow23)) / fSlow29) - 1.0f);
		float fSlow38 = expf((fConst16 / fSlow14));
		float fSlow39 = faustpower2_f(fSlow38);
		float fSlow40 = (1.0f - (fSlow13 * fSlow39));
		float fSlow41 = (1.0f - fSlow39);
		float fSlow42 = (fSlow40 / fSlow41);
		float fSlow43 = sqrtf(max(0.0f, ((faustpower2_f(fSlow40) / faustpower2_f(fSlow41)) - 1.0f)));
		float fSlow44 = (fSlow42 - fSlow43);
		float fSlow45 = (fSlow38 * ((1.0f + fSlow43) - fSlow42));
		float fSlow46 = ((expf((fConst16 / fSlow23)) / fSlow38) - 1.0f);
		float fSlow47 = expf((fConst21 / fSlow14));
		float fSlow48 = faustpower2_f(fSlow47);
		float fSlow49 = (1.0f - (fSlow13 * fSlow48));
		float fSlow50 = (1.0f - fSlow48);
		float fSlow51 = (fSlow49 / fSlow50);
		float fSlow52 = sqrtf(max(0.0f, ((faustpower2_f(fSlow49) / faustpower2_f(fSlow50)) - 1.0f)));
		float fSlow53 = (fSlow51 - fSlow52);
		float fSlow54 = (fSlow47 * ((1.0f + fSlow52) - fSlow51));
		float fSlow55 = ((expf((fConst21 / fSlow23)) / fSlow47) - 1.0f);
		float fSlow56 = expf((fConst26 / fSlow14));
		float fSlow57 = faustpower2_f(fSlow56);
		float fSlow58 = (1.0f - (fSlow13 * fSlow57));
		float fSlow59 = (1.0f - fSlow57);
		float fSlow60 = (fSlow58 / fSlow59);
		float fSlow61 = sqrtf(max(0.0f, ((faustpower2_f(fSlow58) / faustpower2_f(fSlow59)) - 1.0f)));
		float fSlow62 = (fSlow60 - fSlow61);
		float fSlow63 = (fSlow56 * ((1.0f + fSlow61) - fSlow60));
		float fSlow64 = ((expf((fConst26 / fSlow23)) / fSlow56) - 1.0f);
		float fSlow65 = expf((fConst31 / fSlow14));
		float fSlow66 = faustpower2_f(fSlow65);
		float fSlow67 = (1.0f - (fSlow13 * fSlow66));
		float fSlow68 = (1.0f - fSlow66);
		float fSlow69 = (fSlow67 / fSlow68);
		float fSlow70 = sqrtf(max(0.0f, ((faustpower2_f(fSlow67) / faustpower2_f(fSlow68)) - 1.0f)));
		float fSlow71 = (fSlow69 - fSlow70);
		float fSlow72 = (fSlow65 * ((1.0f + fSlow70) - fSlow69));
		float fSlow73 = ((expf((fConst31 / fSlow23)) / fSlow65) - 1.0f);
		float fSlow74 = expf((fConst36 / fSlow14));
		float fSlow75 = faustpower2_f(fSlow74);
		float fSlow76 = (1.0f - (fSlow13 * fSlow75));
		float fSlow77 = (1.0f - fSlow75);
		float fSlow78 = (fSlow76 / fSlow77);
		float fSlow79 = sqrtf(max(0.0f, ((faustpower2_f(fSlow76) / faustpower2_f(fSlow77)) - 1.0f)));
		float fSlow80 = (fSlow78 - fSlow79);
		float fSlow81 = (fSlow74 * ((1.0f + fSlow79) - fSlow78));
		float fSlow82 = ((expf((fConst36 / fSlow23)) / fSlow74) - 1.0f);
		float fSlow83 = expf((fConst41 / fSlow14));
		float fSlow84 = faustpower2_f(fSlow83);
		float fSlow85 = (1.0f - (fSlow84 * fSlow13));
		float fSlow86 = (1.0f - fSlow84);
		float fSlow87 = (fSlow85 / fSlow86);
		float fSlow88 = sqrtf(max(0.0f, ((faustpower2_f(fSlow85) / faustpower2_f(fSlow86)) - 1.0f)));
		float fSlow89 = (fSlow87 - fSlow88);
		float fSlow90 = (fSlow83 * ((1.0f + fSlow88) - fSlow87));
		float fSlow91 = ((expf((fConst41 / fSlow23)) / fSlow83) - 1.0f);
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			float fTemp0 = float(input0[i]);
			fVec0[(IOTA & 8191)] = fTemp0;
			fRec1[0] = (fSlow1 + (0.999000013f * fRec1[1]));
			float fTemp1 = (1.0f + fRec1[0]);
			float fTemp2 = (1.0f - (0.5f * fTemp1));
			float fTemp3 = (fSlow6 * fRec2[1]);
			float fTemp4 = (fSlow11 * fRec3[1]);
			float fTemp5 = (0.300000012f * fVec0[((IOTA - iSlow12) & 8191)]);
			fRec15[0] = ((fSlow27 * (fRec4[1] + fRec4[2])) + (fSlow28 * fRec15[1]));
			fRec14[0] = ((fSlow21 * fRec14[1]) + (fSlow22 * (fRec4[1] + (fSlow24 * fRec15[0]))));
			fVec1[(IOTA & 8191)] = (9.99999968e-21f + (0.353553385f * fRec14[0]));
			float fTemp6 = ((fTemp5 + fVec1[((IOTA - iConst8) & 8191)]) - (0.600000024f * fRec12[1]));
			fVec2[(IOTA & 1023)] = fTemp6;
			fRec12[0] = fVec2[((IOTA - iConst9) & 1023)];
			float fRec13 = (0.600000024f * fTemp6);
			fRec19[0] = ((fSlow27 * (fRec8[1] + fRec8[2])) + (fSlow28 * fRec19[1]));
			fRec18[0] = ((fSlow35 * fRec18[1]) + (fSlow36 * (fRec8[1] + (fSlow37 * fRec19[0]))));
			fVec3[(IOTA & 8191)] = (9.99999968e-21f + (0.353553385f * fRec18[0]));
			float fTemp7 = ((fTemp5 + fVec3[((IOTA - iConst13) & 8191)]) - (0.600000024f * fRec16[1]));
			fVec4[(IOTA & 2047)] = fTemp7;
			fRec16[0] = fVec4[((IOTA - iConst14) & 2047)];
			float fRec17 = (0.600000024f * fTemp7);
			fRec23[0] = ((fSlow27 * (fRec6[1] + fRec6[2])) + (fSlow28 * fRec23[1]));
			fRec22[0] = ((fSlow44 * fRec22[1]) + (fSlow45 * (fRec6[1] + (fSlow46 * fRec23[0]))));
			fVec5[(IOTA & 8191)] = (9.99999968e-21f + (0.353553385f * fRec22[0]));
			float fTemp8 = (fVec5[((IOTA - iConst18) & 8191)] - (fTemp5 + (0.600000024f * fRec20[1])));
			fVec6[(IOTA & 2047)] = fTemp8;
			fRec20[0] = fVec6[((IOTA - iConst19) & 2047)];
			float fRec21 = (0.600000024f * fTemp8);
			fRec27[0] = ((fSlow27 * (fRec10[1] + fRec10[2])) + (fSlow28 * fRec27[1]));
			fRec26[0] = ((fSlow53 * fRec26[1]) + (fSlow54 * (fRec10[1] + (fSlow55 * fRec27[0]))));
			fVec7[(IOTA & 8191)] = (9.99999968e-21f + (0.353553385f * fRec26[0]));
			float fTemp9 = (fVec7[((IOTA - iConst23) & 8191)] - (fTemp5 + (0.600000024f * fRec24[1])));
			fVec8[(IOTA & 1023)] = fTemp9;
			fRec24[0] = fVec8[((IOTA - iConst24) & 1023)];
			float fRec25 = (0.600000024f * fTemp9);
			fRec31[0] = ((fSlow27 * (fRec5[1] + fRec5[2])) + (fSlow28 * fRec31[1]));
			fRec30[0] = ((fSlow62 * fRec30[1]) + (fSlow63 * (fRec5[1] + (fSlow64 * fRec31[0]))));
			fVec9[(IOTA & 16383)] = (9.99999968e-21f + (0.353553385f * fRec30[0]));
			float fTemp10 = float(input1[i]);
			fVec10[(IOTA & 8191)] = fTemp10;
			float fTemp11 = (0.300000012f * fVec10[((IOTA - iSlow12) & 8191)]);
			float fTemp12 = (fVec9[((IOTA - iConst28) & 16383)] + (fTemp11 + (0.600000024f * fRec28[1])));
			fVec11[(IOTA & 2047)] = fTemp12;
			fRec28[0] = fVec11[((IOTA - iConst29) & 2047)];
			float fRec29 = (0.0f - (0.600000024f * fTemp12));
			fRec35[0] = ((fSlow27 * (fRec9[1] + fRec9[2])) + (fSlow28 * fRec35[1]));
			fRec34[0] = ((fSlow71 * fRec34[1]) + (fSlow72 * (fRec9[1] + (fSlow73 * fRec35[0]))));
			fVec12[(IOTA & 8191)] = (9.99999968e-21f + (0.353553385f * fRec34[0]));
			float fTemp13 = (fVec12[((IOTA - iConst33) & 8191)] + (fTemp11 + (0.600000024f * fRec32[1])));
			fVec13[(IOTA & 2047)] = fTemp13;
			fRec32[0] = fVec13[((IOTA - iConst34) & 2047)];
			float fRec33 = (0.0f - (0.600000024f * fTemp13));
			fRec39[0] = ((fSlow27 * (fRec7[1] + fRec7[2])) + (fSlow28 * fRec39[1]));
			fRec38[0] = ((fSlow80 * fRec38[1]) + (fSlow81 * (fRec7[1] + (fSlow82 * fRec39[0]))));
			fVec14[(IOTA & 16383)] = (9.99999968e-21f + (0.353553385f * fRec38[0]));
			float fTemp14 = (((0.600000024f * fRec36[1]) + fVec14[((IOTA - iConst38) & 16383)]) - fTemp11);
			fVec15[(IOTA & 2047)] = fTemp14;
			fRec36[0] = fVec15[((IOTA - iConst39) & 2047)];
			float fRec37 = (0.0f - (0.600000024f * fTemp14));
			fRec43[0] = ((fSlow27 * (fRec11[1] + fRec11[2])) + (fSlow28 * fRec43[1]));
			fRec42[0] = ((fSlow89 * fRec42[1]) + (fSlow90 * (fRec11[1] + (fSlow91 * fRec43[0]))));
			fVec16[(IOTA & 16383)] = (9.99999968e-21f + (0.353553385f * fRec42[0]));
			float fTemp15 = (((0.600000024f * fRec40[1]) + fVec16[((IOTA - iConst43) & 16383)]) - fTemp11);
			fVec17[(IOTA & 1023)] = fTemp15;
			fRec40[0] = fVec17[((IOTA - iConst44) & 1023)];
			float fRec41 = (0.0f - (0.600000024f * fTemp15));
			float fTemp16 = (fRec40[1] + fRec41);
			float fTemp17 = (fRec37 + (fRec36[1] + fTemp16));
			float fTemp18 = (fRec29 + (fRec28[1] + (fRec33 + (fRec32[1] + fTemp17))));
			fRec4[0] = (fRec13 + (fRec12[1] + (fRec17 + (fRec16[1] + (fRec21 + (fRec20[1] + (fRec25 + (fRec24[1] + fTemp18))))))));
			fRec5[0] = (0.0f - (fTemp18 - (fRec13 + (fRec12[1] + (fRec17 + (fRec16[1] + (fRec21 + (fRec20[1] + (fRec24[1] + fRec25)))))))));
			float fTemp19 = (fRec29 + (fRec28[1] + (fRec32[1] + fRec33)));
			fRec6[0] = (0.0f - ((fRec21 + (fRec20[1] + (fRec25 + (fRec24[1] + fTemp17)))) - (fRec13 + (fRec12[1] + (fRec17 + (fRec16[1] + fTemp19))))));
			fRec7[0] = (0.0f - ((fRec21 + (fRec20[1] + (fRec25 + (fRec24[1] + fTemp19)))) - (fRec13 + (fRec12[1] + (fRec17 + (fRec16[1] + fTemp17))))));
			float fTemp20 = (fRec33 + (fRec32[1] + fTemp16));
			float fTemp21 = (fRec36[1] + fRec37);
			float fTemp22 = (fRec29 + (fRec28[1] + fTemp21));
			fRec8[0] = (0.0f - ((fRec17 + (fRec16[1] + (fRec25 + (fRec24[1] + fTemp20)))) - (fRec13 + (fRec12[1] + (fRec21 + (fRec20[1] + fTemp22))))));
			fRec9[0] = (0.0f - ((fRec17 + (fRec16[1] + (fRec25 + (fRec24[1] + fTemp22)))) - (fRec13 + (fRec12[1] + (fRec21 + (fRec20[1] + fTemp20))))));
			float fTemp23 = (fRec33 + (fRec32[1] + fTemp21));
			float fTemp24 = (fRec29 + (fRec28[1] + fTemp16));
			fRec10[0] = (0.0f - ((fRec17 + (fRec16[1] + (fRec21 + (fRec20[1] + fTemp23)))) - (fRec13 + (fRec12[1] + (fRec25 + (fRec24[1] + fTemp24))))));
			fRec11[0] = (0.0f - ((fRec17 + (fRec16[1] + (fRec21 + (fRec20[1] + fTemp24)))) - (fRec13 + (fRec12[1] + (fRec25 + (fRec24[1] + fTemp23))))));
			float fTemp25 = (0.370000005f * (fRec5[0] + fRec6[0]));
			fRec3[0] = (0.0f - ((fTemp4 + (fSlow10 * fRec3[2])) - fTemp25));
			float fTemp26 = (fSlow10 * fRec3[0]);
			float fTemp27 = (fTemp4 + fRec3[2]);
			float fTemp28 = (0.5f * ((fSlow7 * ((fTemp26 + fTemp27) - fTemp25)) + (fTemp26 + (fTemp25 + fTemp27))));
			fRec2[0] = (0.0f - ((fTemp3 + (fSlow5 * fRec2[2])) - fTemp28));
			float fTemp29 = ((fSlow5 * fRec2[0]) + (fTemp3 + fRec2[2]));
			output0[i] = FAUSTFLOAT((fRec0[0] * ((fTemp0 * fTemp2) + (0.25f * (fTemp1 * ((fSlow2 * (fTemp29 - fTemp28)) + (fTemp28 + fTemp29)))))));
			float fTemp30 = (fSlow6 * fRec44[1]);
			float fTemp31 = (fSlow11 * fRec45[1]);
			float fTemp32 = (0.370000005f * (fRec5[0] - fRec6[0]));
			fRec45[0] = (0.0f - ((fTemp31 + (fSlow10 * fRec45[2])) - fTemp32));
			float fTemp33 = (fSlow10 * fRec45[0]);
			float fTemp34 = (fTemp31 + fRec45[2]);
			float fTemp35 = (0.5f * ((fTemp33 + (fTemp32 + fTemp34)) + (fSlow7 * ((fTemp33 + fTemp34) - fTemp32))));
			fRec44[0] = (0.0f - ((fTemp30 + (fSlow5 * fRec44[2])) - fTemp35));
			float fTemp36 = ((fSlow5 * fRec44[0]) + (fTemp30 + fRec44[2]));
			output1[i] = FAUSTFLOAT((fRec0[0] * ((fTemp10 * fTemp2) + (0.25f * (fTemp1 * ((fSlow2 * (fTemp36 - fTemp35)) + (fTemp35 + fTemp36)))))));
			fRec0[1] = fRec0[0];
			IOTA = (IOTA + 1);
			fRec1[1] = fRec1[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec12[1] = fRec12[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec16[1] = fRec16[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec20[1] = fRec20[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[1] = fRec28[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec32[1] = fRec32[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec36[1] = fRec36[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec40[1] = fRec40[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec6[2] = fRec6[1];
			fRec6[1] = fRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fRec8[2] = fRec8[1];
			fRec8[1] = fRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec45[2] = fRec45[1];
			fRec45[1] = fRec45[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			
		}
		
	}

	
};


#endif
