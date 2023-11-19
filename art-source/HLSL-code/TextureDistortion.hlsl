float3 rayStep = viewDir * -1; // for Raymarching
float depthValue = depth;
float4 color;

float distMag = magnitude;
float distFreq = frequency;
float distSpeed = speed;
float primDistStr = primDistStrength;

struct texDistort
{
    float2 textScale(float2 uv, float2 scale)
    {
        float2 texScale = (uv - 0.5) * scale + 0.5; // .5 value is to scale from center of texture (0,0 would be top left corner)
        return texScale;
    }

    float2 texRotate(float2 uv, float angle)
    {
        float2x2 rotationMatrix = float2x2(cos(angle), sin(angle),
                                            -sin(angle), cos(angle)); // swapping signs of middle values changes rotation direction float2x2(a, -b, c, d) & float2x2(a, b, -c, d)
        return mul(uv - 0.5, rotationMatrix) + 0.5;
    }

    float2 texDistortion(float2 uv, float time)
    {
        float angle = atan2(uv.y - 0.5, uv.x - 0.5); // angle from uv coord to center of uv space
        float radius = length(uv - 0.5); // distance from uv coord to center of uv space


        float distortion = distMag * sin(distFreq * radius + distSpeed * time); // sin wave distortion by a magnitude, frequency and speed value.
        float primDist = sin(primDistStrength * angle) * distortion; // secon layer of distortion. 6.0 is an intensity value

        return texRotate(uv, primDist);
    }
};
texDistort txd; // Give the struct a propper name

for (int i = 0; i < 5; i++)
{
    color = Texture2DSample(texObject, texObjectSampler, txd.texDistortion(uv, time));

    if(color.r > 0.1 && color.g > 0.1 && color.b > 0.1)
    {
        return color * float3(1,0,0); // color multiplied by a red value
    }
    else if(color.r > 0.01 && color.g > 0.01 && color.b > 0.01)
    {   
        return color * float3(0,1,1); // Color multiplied by green/blue value
    }

    uv += rayStep * depth;
}

return(color);