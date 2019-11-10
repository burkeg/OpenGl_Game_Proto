float cycleR(float color, float growth_rate)
{
	static float orientation = 1.0;
	if ((color + growth_rate) > 1.0f)
	{
		orientation = -1.0;
	}
	if ((color - growth_rate) < 0.0f)
	{
		orientation = 1.0;
	}
	color += (orientation * growth_rate);
	return color;
}

float cycleG(float color, float growth_rate)
{
	static float orientation = 1.0;
	if ((color + growth_rate) > 1.0f)
	{
		orientation = -1.0;
	}
	if ((color - growth_rate) < 0.0f)
	{
		orientation = 1.0;
	}
	color += (orientation * growth_rate);
	return color;
}

float cycleB(float color, float growth_rate)
{
	static float orientation = 1.0;
	if ((color + growth_rate) > 1.0f)
	{
		orientation = -1.0;
	}
	if ((color - growth_rate) < 0.0f)
	{
		orientation = 1.0;
	}
	color += (orientation * growth_rate);
	return color;
}