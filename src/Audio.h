#pragma once
#include "fft.h"
#include "ofMain.h"
#include "SmoothValue.h"

#define BUFFER_SIZE 256
#define NUM_WINDOWS 80

class Audio {

	public:
		Audio();
		vector <float> left;
		vector <float> right;
		vector <float> volHistory;
		
		
		void update(float * input, int bufferSize);
		void calc();
		float getBass();
		float getVol();

	private:
		fft		myfft;
		float * data;

		SmoothValue volume;
		SmoothValue bass;
		float phase[BUFFER_SIZE];
		float power[BUFFER_SIZE];
		float magnitude[BUFFER_SIZE];
		float freq[NUM_WINDOWS][BUFFER_SIZE/2];
		float freq_phase[NUM_WINDOWS][BUFFER_SIZE/2];
};